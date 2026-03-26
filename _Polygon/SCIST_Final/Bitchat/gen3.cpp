#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    Point(int xx, int yy): x(xx), y(yy) {}
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);




    // ==== 參數設定 請勿修改 ====
    
    int sub , N , R , T , K , M , Q;


    // 自動輸入
    // sub = atoi(argv[1]);   // 支援的最大操作類型
    // N = atoi(argv[2]);   // 節點總數
    // R = rnd.next(250, 300);     // 群集內最大連線距離
    // T = rnd.next(7, 10);      // TTL
    // K = atoi(argv[3]);    // 群集數量
    // M = atoi(argv[4]);    // 坐標範圍限制
    // Q = atoi(argv[5]);

    // 手動輸入
    cin >> sub >> N >> K >> M >> Q;
    
    T = rnd.next(7, 10); 
    R = 300;
    // R = rnd.next(250, 300);     // 群集內最大連線距離
    
    
    // N = rnd.next(N-10, N); 
    // K = rnd.next(N-3, N);
    // Q = rnd.next(Q-10, Q);

    cout << N << " " << R << " " << T << '\n';

    // ==== 參數設定 請勿修改 ====







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
        if (!placed) {
            centers.emplace_back(rnd.next(-M, M), rnd.next(-M, M));
        }
    }
    // ==== 產生群集中心 ====






    // centers 原本是 vector<Point>
    // 現在改成 vector<vector<Point>> 用來存放每個群集生成的所有點
    vector<vector<Point>> cluster_points(K);

    // 1. 隨機分配每個群集的點數
    vector<int> cluster_sizes(K, 1);  // 先保證每個中心至少有 1 個
    int remaining = N - K;            // 扣掉中心點
    for (int i = 0; i < remaining; ++i) {
        int c = rnd.next(0, K-1);
        cluster_sizes[c]++;
    }

    // 2. BFS 擴散生成每個群集的點
    // int max_layers = 10;
    // int max_branch = 5;
    // for (int c = 0; c < K; ++c) {
    //     int need = cluster_sizes[c];
    //     queue<Point> q;
    //     q.push(centers[c]);
    //     cluster_points[c].push_back(centers[c]);
    //     need--;

    //     int layer = 0;
    //     while (need > 0 && !q.empty() && layer < max_layers) {
    //         int sz = (int)q.size();
    //         for (int i = 0; i < sz && need > 0; ++i) {
    //             Point cur = q.front(); q.pop();

    //             int branches = rnd.next(1, max_branch);
    //             for (int b = 0; b < branches && need > 0; ++b) {
    //                 int angle = rnd.next(0, 359);
    //                 double rad = angle * M_PI / 180.0;
    //                 int dist = rnd.next(R / 3, R);
    //                 int nx = cur.x + int(dist * cos(rad));
    //                 int ny = cur.y + int(dist * sin(rad));

    //                 cluster_points[c].emplace_back(nx, ny);
    //                 q.push(cluster_points[c].back());
    //                 need--;
    //             }
    //         }
    //         layer++;
    //     }

    //     // 若還沒足夠點，隨機補點在群集中心附近
    //     while (need > 0) {
    //         int nx = centers[c].x + rnd.next(-R, R);
    //         int ny = centers[c].y + rnd.next(-R, R);
    //         cluster_points[c].emplace_back(nx, ny);
    //         need--;
    //     }
    // }





    // ====  2. 改進 BFS 擴散生成每個群集的點 ====

    int max_layers = T * 2;   // 擴散層數限制
    int max_branch = 2;       // 每個點最多能往外擴幾個
    for (int c = 0; c < K; ++c) {
        int need = cluster_sizes[c];
        queue<pair<Point,int>> q; // (點, 當前層數)
        q.push({centers[c], 0});
        cluster_points[c].push_back(centers[c]);
        need--;

        while (need > 0 && !q.empty()) {
            auto [cur, layer] = q.front(); q.pop();
            if (layer >= max_layers) continue;

            int branches = rnd.next(1, max_branch);
            for (int b = 0; b < branches && need > 0; ++b) {
                int nx, ny;
                // 在正方形範圍內隨機，直到落在中心半徑 R 內
                for (int attempt = 0; attempt < 10; ++attempt) {
                    nx = cur.x + rnd.next(-R, R);
                    ny = cur.y + rnd.next(-R, R);
                    int dx = nx - centers[c].x, dy = ny - centers[c].y;
                    if (1LL*dx*dx + 1LL*dy*dy <= 1LL*R*R) {
                        cluster_points[c].push_back(Point(nx, ny));
                        q.push({Point(nx, ny), layer+1});
                        need--;
                        break;
                    }
                }
            }
        }

        // 若還沒足夠點，隨機補在半徑內
        while (need > 0) {
            int nx = centers[c].x + rnd.next(-R, R);
            int ny = centers[c].y + rnd.next(-R, R);
            int dx = nx - centers[c].x, dy = ny - centers[c].y;
            if (1LL*dx*dx + 1LL*dy*dy <= 1LL*R*R) {
                cluster_points[c].emplace_back(nx, ny);
                need--;
            }
        }
    }
    // ====  2. 改進 BFS 擴散生成每個群集的點 ====







    // // ==== 輸出群集中心坐標 請勿修改 ====
    // for (auto &p : centers) {
    //     cout << p.x << " " << p.y << '\n';
    // }
    // // ==== 輸出群集中心坐標 請勿修改 ====






    // ==== 輸出測試，先看生成結果 ====
    for (int c = 0; c < K; ++c) {
        // cout << "Cluster " << c+1 << " (" << cluster_points[c].size() << " points):\n";
        for (auto &p : cluster_points[c])
            cout << p.x << " " << p.y << '\n';
    }
    // ==== 輸出測試，先看生成結果 ====







    // // ==== 輸出 Q 操作 請勿修改 ====

    // cout << Q << '\n';
    // for (int i = 0; i < Q; ++i) 
    // {
    //     int op = (sub == 3 ? rnd.next(1, 2): sub);
    //     int a = rnd.next(1, N);
    //     int b = rnd.next(1, N);
    //     while (a == b) b = rnd.next(1, N);
    //     cout << op << " " << a << " " << b << '\n';
    // }
    // // ==== 輸出 Q 操作 請勿修改 ====
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
