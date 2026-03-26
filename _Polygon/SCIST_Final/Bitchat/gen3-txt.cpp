#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

// 定義一個點結構
struct Point {
    int x, y;
    Point(int xx, int yy): x(xx), y(yy) {}
};

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // ======== 基本參數設定 ========
    int N = 10000;          // 節點總數
    int R = 1000;           // 最大連線距離（群集內點偏移範圍）
    int T = 20;             // TTL（跳數上限）
    vector<string> output_lines; // 暫存輸出

    string line = to_string(N) + " " + to_string(R) + " " + to_string(T);
    cout << line << '\n';
    output_lines.push_back(line);

    // ======== 生成群集中心 ========
    int K = 100;            // 群集數量
    vector<Point> centers;
    for (int i = 0; i < K; ++i) {
        centers.emplace_back(
            rnd.wnext(-10000, 10000, 2),
            rnd.wnext(-10000, 10000, 2)
        );
    }

    // ======== 分配每個群集的點數 ========
    vector<int> cluster_sizes(K, N / K);
    for (int i = 0; i < N % K; ++i) cluster_sizes[i]++;

    vector<Point> points;          // 所有節點
    vector<int> cluster_of_point;  // 記錄每個節點屬於哪個群集

    // ======== 生成群集內的點 ========
    for (int c = 0; c < K; ++c) {
        int need = cluster_sizes[c];
        queue<Point> q;
        q.push(centers[c]);
        points.push_back(centers[c]);
        cluster_of_point.push_back(c);
        need--;

        int max_layers = 10;
        int max_branch = 5;
        int layer = 0;

        while (need > 0 && !q.empty() && layer < max_layers) {
            int sz = (int)q.size();
            for (int i = 0; i < sz && need > 0; ++i) {
                Point cur = q.front(); q.pop();
                int branches = rnd.next(1, max_branch);
                for (int b = 0; b < branches && need > 0; ++b) {
                    // 隨機偏移生成新點，保證在距離 R 內
                    int angle = rnd.next(0, 359);
                    double rad = angle * std::acos(-1) / 180.0; // 使用標準 acos(-1) 得到 pi
                    int dist = rnd.next(R / 3, R);
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

        while (need > 0) {
            int nx = centers[c].x + rnd.wnext(-R, R, 2);
            int ny = centers[c].y + rnd.wnext(-R, R, 2);
            points.emplace_back(nx, ny);
            cluster_of_point.push_back(c);
            need--;
        }
    }

    // ======== 輸出所有節點座標 ========
    for (auto &p : points) {
        line = to_string(p.x) + " " + to_string(p.y);
        cout << line << '\n';
        output_lines.push_back(line);
    }

    // ======== 生成查詢 ========
    int Q = 100000;
    line = to_string(Q);
    cout << line << '\n';
    output_lines.push_back(line);

    vector<int> op(Q), a(Q), b(Q); // 暫存查詢
    for (int i = 0; i < Q; ++i) {
        op[i] = rnd.next(1, 2);
        if (op[i] == 2) {
            // op=2 查詢：集中在同一聯通塊
            int cluster = rnd.next(0, K - 1);
            vector<int> cluster_points;
            for (int j = 0; j < (int)points.size(); ++j)
                if (cluster_of_point[j] == cluster)
                    cluster_points.push_back(j);

            int sz = (int)cluster_points.size();
            a[i] = cluster_points[rnd.next(0, sz - 1)] + 1;
            b[i] = cluster_points[rnd.next(0, sz - 1)] + 1;
            while (b[i] == a[i])
                b[i] = cluster_points[rnd.next(0, sz - 1)] + 1;
        } else {
            a[i] = rnd.next(1, N);
            b[i] = rnd.next(1, N);
            while (b[i] == a[i])
                b[i] = rnd.next(1, N);
        }

        line = to_string(op[i]) + " " + to_string(a[i]) + " " + to_string(b[i]);
        cout << line << '\n';
        output_lines.push_back(line);
    }

    // ======== 將測資寫入 txt 檔案 ========
    ofstream fout("testcase.txt");
    for (auto &l : output_lines)
        fout << l << '\n';
    fout.close();

    return 0;
}
