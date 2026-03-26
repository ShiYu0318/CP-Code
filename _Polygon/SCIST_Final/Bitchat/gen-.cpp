#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846

struct Point {
    int x, y;
    Point(int xx, int yy): x(xx), y(yy) {}
};

int main() {

    int N = rnd.next(500, 1000);   // 總點數
    int R = rnd.next(100, 300);   // 最大距離
    int T = rnd.next(10, 20);      // TTL（最多跳數）
    cout << N << " " << R << " " << T << '\n';
    int K = rnd.next(15, 25);       // 群集數
    vector<Point> centers;

    // 產生群集中心，彼此距離至少 R*3，避免過度重疊
    for (int i = 0; i < K; ++i) {
        bool placed = false;
        for (int attempt = 0; attempt < 1000; ++attempt) {
            int cx = rnd.wnext(-1000, 1000, 2);
            int cy = rnd.wnext(-1000, 1000, 2);
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
            centers.emplace_back(rnd.wnext(-1000, 1000, 2), rnd.wnext(-1000, 1000, 2));
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

    // 有機會製造跨群集點
    int cross_edges = rnd.next(K, 2 * K);
    for (int i = 0; i < cross_edges; ++i) {
        int c1 = rnd.next(0, K - 1);
        int c2 = (c1 + rnd.next(1, K - 1)) % K; // 保證不同群集
        if (cluster_sizes[c1] > 0 && cluster_sizes[c2] > 0) {
            // 把 c1 群集最後一點移動到靠近 c2 群集中心附近，增加跨群連線機會
            for (int j = (int)points.size() - 1; j >= 0; --j) {
                if (cluster_of_point[j] == c1) {
                    points[j].x = centers[c2].x + rnd.wnext(-R / 2, R / 2, 2);
                    points[j].y = centers[c2].y + rnd.wnext(-R / 2, R / 2, 2);
                    break;
                }
            }
        }
    }

    // 打印所有點
    for (auto &p : points) {
        cout << p.x << " " << p.y << '\n';
    }
    int op_sub; cin >> op_sub;// 支援的最大操作類型 (1 = 子題1, 2 = 子題2, 3 = 子題3)

    // 查詢生成
    int Q = rnd.next(20, 30);
    cout << Q << '\n';
    for (int i = 0; i < Q; ++i) {
        int op = (op_sub == 3 ? rnd.next(1, 2): op_sub);
        int a = rnd.next(1, (int)points.size());
        int b = rnd.next(1, (int)points.size());
        while (a == b) b = rnd.next(1, (int)points.size());
        cout << op << " " << a << " " << b << '\n';
    }

    return 0;
}
