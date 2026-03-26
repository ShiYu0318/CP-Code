#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Point {
    int x, y;
    Point(int xx, int yy): x(xx), y(yy) {}
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    
    int sub , N , R , T , Q , K , M ;

    // 手動輸入
    cin >> sub >> N >> R >> T >> Q >> K >> M;

    // 自動輸入
    // sub = atoi(argv[1]);   // 支援的最大操作類型
    // N = atoi(argv[2]);   // 節點總數
    // R = atoi(argv[3]);
    // T = atoi(argv[4]);
    // Q = atoi(argv[5]);
    // K = atoi(argv[6]);    // 群集數量
    // M = atoi(argv[7]);    // 坐標範圍限制
    
    
    N = rnd.next(N-10, N); 
    R = rnd.next(R-2, R);
    T = rnd.next(T-2, T);
    Q = rnd.next(Q-10, Q);
    K = rnd.next(N-3, N);


    cout << N << " " << R << " " << T << '\n';



    vector<Point> centers;

    // 產生群集中心，彼此距離至少 R*3，避免過度重疊
    for (int i = 0; i < K; ++i) {
        bool placed = false;
        for (int attempt = 0; attempt < 1000; ++attempt) {
            int cx = rnd.next(-M, M);
            int cy = rnd.next(-M, M);
            bool ok = true;
            for (auto &c : centers) {
                int dx = cx - c.x, dy = cy - c.y;
                if (1LL * dx * dx + 1LL * dy * dy < 9LL * R * R) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                centers.emplace_back(cx, cy);
                placed = true;
                break;
            }
        }
        if (!placed) {
            // 無法放置新的群集中心，放寬條件或強制加入
            // 可以直接插入，或調整距離限制
            centers.emplace_back(rnd.next(-M, M), rnd.next(-M, M));
        }
    }


    // 每群集點數（均分為主，也可隨意分配）
    vector<int> cluster_sizes(K, N / K);
    for (int i = 0; i < N % K; ++i) cluster_sizes[i]++;

    vector<Point> points;
    vector<int> cluster_of_point;

    // 對每個群集做擴散生成，類似 BFS
    // 參數可調: 每層最多新點數, 最大擴散層數
    int max_layers = 10;
    int max_branch = 5;

    for (int c = 0; c < K; ++c) {
        int need = cluster_sizes[c];
        queue<Point> q;
        q.push(centers[c]);
        points.push_back(centers[c]);
        cluster_of_point.push_back(c);
        need--;

        // 每層擴散
        int layer = 0;
        while (need > 0 && !q.empty() && layer < max_layers) {
            int sz = (int)q.size();
            for (int i = 0; i < sz && need > 0; ++i) {
                Point cur = q.front(); q.pop();

                int branches = rnd.next(1, max_branch);
                for (int b = 0; b < branches && need > 0; ++b) {
                    // 新點隨機偏移 (小於 R)
                    int angle = rnd.next(0, 359);
                    double rad = angle * M_PI / 180.0;
                    int dist = rnd.next(R / 3, R);  // 保證一定連接距離內
                    int nx = cur.x + int(dist * cos(rad));
                    int ny = cur.y + int(dist * sin(rad));
                    points.emplace_back(nx, ny);
                    cluster_of_point.push_back(c);
                    q.push(points.back());
                    need--;
                }
            }
            layer++;
        }

        // 若還沒足夠點，隨機補點在群集中心附近
        while (need > 0) {
            int nx = centers[c].x + rnd.wnext(-R, R, 2);
            int ny = centers[c].y + rnd.wnext(-R, R, 2);
            points.emplace_back(nx, ny);
            cluster_of_point.push_back(c);
            need--;
        }
    }


    // 打印所有點
    for (auto &p : points) {
        cout << p.x << " " << p.y << '\n';
    }
    

    // 查詢生成
    cout << Q << '\n';
    for (int i = 0; i < Q; ++i) {
        int op = (sub == 3 ? rnd.next(1, 2): sub);
        int a = rnd.next(1, (int)points.size());
        int b = rnd.next(1, (int)points.size());
        while (a == b) b = rnd.next(1, (int)points.size());
        cout << op << " " << a << " " << b << '\n';
    }

    return 0;
}
