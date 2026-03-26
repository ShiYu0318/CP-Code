#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int xx, int yy): x(xx), y(yy) {}
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
//#################################################################################################################################################


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
//#################################################################################################################################################

    // ==== 產生群集中心 ====
    vector<Point> centers;
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
        if (!placed) centers.emplace_back(rnd.next(-M, M), rnd.next(-M, M));
    }
    // ==== 產生群集中心 ====
//#################################################################################################################################################

    // ==== 保留一些預留點，用於連接群集 ====
    int reserved_points = N / 5; // 比如 20% 作為預留點
    reserved_points = min(reserved_points, N - K); // 保證不超 N
    int remaining_points = N - reserved_points;
//#################################################################################################################################################

    // ==== 生成每個群集點數 ====
    vector<int> cluster_sizes(K, 1);
    int need_points = remaining_points - K;
    for (int i = 0; i < need_points; ++i) {
        int c = rnd.next(0, K-1);
        cluster_sizes[c]++;
    }
//#################################################################################################################################################

    // ==== BFS 擴散生成每個群集點 ====
    vector<vector<Point>> cluster_points(K);
    int max_layers = T * 2;
    int max_branch = 2;

    int total_points = 0;
    for (int c = 0; c < K; ++c) {
        int need = cluster_sizes[c];
        queue<pair<Point,int>> q;
        q.push({centers[c], 0});
        cluster_points[c].push_back(centers[c]);
        total_points++;
        need--;

        while (need > 0 && !q.empty() && total_points < N - reserved_points) {
            auto [cur, layer] = q.front(); q.pop();
            if (layer >= max_layers) continue;

            int branches = rnd.next(1, max_branch);
            for (int b = 0; b < branches && need > 0 && total_points < N - reserved_points; ++b) {
                int nx, ny;
                for (int attempt = 0; attempt < 10; ++attempt) {
                    nx = cur.x + rnd.next(-R, R);
                    ny = cur.y + rnd.next(-R, R);
                    int dx = nx - centers[c].x, dy = ny - centers[c].y;
                    if (1LL*dx*dx + 1LL*dy*dy <= 1LL*R*R) {
                        cluster_points[c].push_back(Point(nx, ny));
                        q.push({Point(nx, ny), layer+1});
                        need--;
                        total_points++;
                        break;
                    }
                }
            }
        }

        while (need > 0 && total_points < N - reserved_points) {
            int nx = centers[c].x + rnd.next(-R, R);
            int ny = centers[c].y + rnd.next(-R, R);
            int dx = nx - centers[c].x, dy = ny - centers[c].y;
            if (1LL*dx*dx + 1LL*dy*dy <= 1LL*R*R) {
                cluster_points[c].emplace_back(nx, ny);
                need--;
                total_points++;
            }
        }
    }
//##############################################################################################################################################

    // ==== 利用預留點連接不同群集 ====
    vector<Point> reserved;
    while (reserved_points > 0 && total_points < N) {
        int c1 = rnd.next(0, K-1);
        int c2 = rnd.next(0, K-1);
        if (c1 == c2) continue;

        int sz1 = int(cluster_points[c1].size());
        int sz2 = int(cluster_points[c2].size());
        Point A = cluster_points[c1][rnd.next(0, sz1-1)];
        Point B = cluster_points[c2][rnd.next(0, sz2-1)];

        Point cur = A;
        while (true && total_points < N) {
            int dx = B.x - cur.x;
            int dy = B.y - cur.y;
            double dist = sqrt(1.0*dx*dx + 1.0*dy*dy);
            if (dist <= R) break;

            double step = rnd.next(1, R);
            int nx = cur.x + int(round(dx / dist * step));
            int ny = cur.y + int(round(dy / dist * step));

            reserved.emplace_back(nx, ny);
            cluster_points[c1].push_back(reserved.back());
            total_points++;
            if (total_points >= N) break;
            cur = reserved.back();
        }

        if (!(cur.x == B.x && cur.y == B.y) && total_points < N) {
            reserved.emplace_back(B.x, B.y);
            cluster_points[c1].push_back(reserved.back());
            total_points++;
        }

        reserved_points--;
    }
//################################################################################################################################################

    // ==== 輸出所有點 ====
    // int i=1;
    for (int c = 0; c < K; ++c) {
        for (auto &p : cluster_points[c]) {
            cout << p.x << " " << p.y << '\n';
        }
    }
//################################################################################################################################################

    // // ==== 輸出 Q 操作 ====
    // cout << Q << '\n';
    // for (int i = 0; i < Q; ++i) {
    //     int op = (sub == 3 ? rnd.next(1, 2): sub);
    //     int a, b;

    //     // if (rnd.next(1,5) <= 4) {
    //         int c = rnd.next(0, K-1);
    //         int sz = int(cluster_points[c].size());
    //         a = rnd.next(1, sz);
    //         b = rnd.next(1, sz);
    //         while (a == b) b = rnd.next(1, sz);
    //         a = a + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c, 0);
    //         b = b + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c, 0);
    //         a++; b++;
    //     // } else {
    //     //     int c1 = rnd.next(0, K-1);
    //     //     int c2 = rnd.next(0, K-1);
    //     //     while (c2 == c1) c2 = rnd.next(0, K-1);
    //     //     int sz1 = int(cluster_points[c1].size());
    //     //     int sz2 = int(cluster_points[c2].size());
    //     //     a = rnd.next(1, sz1);
    //     //     b = rnd.next(1, sz2);
    //     //     a = a + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c1, 0);
    //     //     b = b + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c2, 0);
    //     //     a++; b++;
    //     // }

    //     cout << op << " " << a << " " << b << '\n';
    // }

//##############################################################################################################################################
    cout << Q << '\n';
    for (int i = 0; i < Q; ++i) 
    {
        int op = (sub == 3 ? rnd.next(1, 2): sub);
        int a, b;

        // 3/4 機率生成可達 (Yes)
        if (rnd.next(1,4) <= 3) {
            // 隨機選一個群集
            int c = rnd.next(0, K-1);
            int sz = cluster_points[c].size();
            a = rnd.next(1, sz);
            b = rnd.next(1, sz);
            while (a == b) b = rnd.next(1, sz);
            
            // 將 a, b 轉成全局點編號
            a = a + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c, 0);
            b = b + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c, 0);
            a++; b++; // 1-based
        }
        else {
            // 1/4 機率生成不可達 (No)
            // 選不同群集
            int c1 = rnd.next(0, K-1);
            int c2 = rnd.next(0, K-1);
            while (c2 == c1) c2 = rnd.next(0, K-1);

            int sz1 = cluster_points[c1].size();
            int sz2 = cluster_points[c2].size();

            a = rnd.next(1, sz1);
            b = rnd.next(1, sz2);

            a = a + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c1, 0);
            b = b + accumulate(cluster_sizes.begin(), cluster_sizes.begin() + c2, 0);
            a++; b++;
        }

        cout << op << " " << a << " " << b << '\n';
    }
}