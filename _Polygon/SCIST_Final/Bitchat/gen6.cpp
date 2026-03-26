#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct Point { int x, y; Point(int xx, int yy): x(xx), y(yy) {} };

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);



    int sub , N , R , T , K , M , Q;

    // 手動輸入
    cin >> sub >> N >> K >> M >> Q;

    // 自動輸入
    // sub = atoi(argv[1]);   // 支援的最大操作類型
    // N = atoi(argv[2]);   // 節點總數
    // K = atoi(argv[3]);    // 群集數量
    // M = atoi(argv[4]);    // 坐標範圍限制
    // Q = atoi(argv[5]);
    
    R = 10;

    // R = rnd.next(250, 300);     // 群集內最大連線距離
    T = rnd.next(7, 10);      // TTL

    
    N = rnd.next(N-10, N); 
    K = rnd.next(N-3, N);
    Q = rnd.next(Q-10, Q);

    cout << N << " " << R << " " << T << '\n';

    // ==== 參數設定 請勿修改 ====

    // ==== 產生群集中心 ====
    vector<Point> centers;
    for (int i = 0; i < K; ++i) {
        bool placed = false;
        for (int attempt = 0; attempt < 1000; ++attempt) {
            int cx = rnd.next(-M, M), cy = rnd.next(-M, M);
            bool ok = true;
            for (auto &c : centers) {
                int dx = cx - c.x, dy = cy - c.y;
                if (1LL*dx*dx + 1LL*dy*dy < 9LL*R*R) { ok=false; break; }
            }
            if(ok){ centers.emplace_back(cx,cy); placed=true; break; }
        }
        if(!placed) centers.emplace_back(rnd.next(-M,M), rnd.next(-M,M));
    }

    // ==== 保留預留點 ====
    int reserved_points = N/5;
    reserved_points = min(reserved_points, N-K);
    int remaining_points = N - reserved_points;

    // ==== 生成群集大小 ====
    vector<int> cluster_sizes(K,1);
    int need_points = remaining_points-K;
    for(int i=0;i<need_points;++i){
        int c = rnd.next(0,K-1);
        cluster_sizes[c]++;
    }

    // ==== BFS-like 擴散生成群集點（安全版） ====
    vector<vector<Point>> cluster_points(K);
    int total_points=0;
    for(int c=0;c<K;++c){
        cluster_points[c].push_back(centers[c]);
        total_points++;
        int need = cluster_sizes[c]-1;
        for(int layer=1;layer<=T && need>0;++layer){
            int layer_points = min(need, 2*layer); // 每層固定生成數量
            for(int i=0;i<layer_points;++i){
                int nx = centers[c].x + rnd.next(-R,R);
                int ny = centers[c].y + rnd.next(-R,R);
                cluster_points[c].emplace_back(nx,ny);
                total_points++; need--;
                if(total_points>=N-reserved_points) break;
            }
        }
        // 若還不足，直接生成剩餘點
        while(need>0 && total_points<N-reserved_points){
            int nx = centers[c].x + rnd.next(-R,R);
            int ny = centers[c].y + rnd.next(-R,R);
            cluster_points[c].emplace_back(nx,ny);
            total_points++; need--;
        }
    }

    // ==== 連接不同群集的 reserved points（線性生成） ====
    vector<Point> reserved;
    while(reserved_points>0 && total_points<N){
        int c1=rnd.next(0,K-1), c2=rnd.next(0,K-1);
        if(c1==c2) continue;
        Point A = cluster_points[c1][rnd.next(0,int(cluster_points[c1].size())-1)];
        Point B = cluster_points[c2][rnd.next(0,int(cluster_points[c2].size())-1)];

        int steps = max(1,(int)ceil(sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y))/R));
        for(int s=1;s<=steps && reserved_points>0 && total_points<N;++s){
            int nx = A.x + (B.x-A.x)*s/steps;
            int ny = A.y + (B.y-A.y)*s/steps;
            reserved.emplace_back(nx,ny);
            cluster_points[c1].push_back(reserved.back());
            total_points++;
            reserved_points--;
        }
    }

    // ==== 輸出所有點 ====
    for(int c=0;c<K;++c)
        for(auto &p:cluster_points[c])
            cout << p.x << " " << p.y << '\n';

    // ==== 預先計算 cluster 起始 index ====
    vector<int> cluster_start(K,0);
    for(int i=1;i<K;++i) cluster_start[i] = cluster_start[i-1] + int(cluster_points[i-1].size());

    // ==== 輸出 Q 操作 ====
    cout << Q << '\n';
    for(int i=0;i<Q;++i){
        int op = (sub==3 ? rnd.next(1,2):sub);
        int c = rnd.next(0,K-1);
        int sz = int(cluster_points[c].size());
        int a=rnd.next(1,sz), b=rnd.next(1,sz);
        while(a==b) b=rnd.next(1,sz);
        a += cluster_start[c]; b += cluster_start[c];
        cout << op << " " << a << " " << b << '\n';
    }
}
