#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int N = rnd.next(100, 1000);    // 總點數
    int R = rnd.next(100, 300);     // 距離限制
    int T = rnd.next(5, 15);        // 跳數限制
    cout << N << " " << R << " " << T << '\n';

    // 產生 K 個群集
    int K = rnd.next(5, 10);
    vector<pair<int,int>> cluster_centers;

    // 產生群集中心，彼此距離至少 R*2 避免跨群集連通
    for(int i=0; i<K; ++i) {
        int cx, cy;
        bool valid = false;
        while(!valid) {
            cx = rnd.wnext(-10000, 10000, 2);
            cy = rnd.wnext(-10000, 10000, 2);
            valid = true;
            for(auto &p : cluster_centers) {
                int dx = cx - p.first;
                int dy = cy - p.second;
                if(1LL*dx*dx + 1LL*dy*dy < 4LL*R*R) { // 距離至少 2R
                    valid = false; break;
                }
            }
        }
        cluster_centers.push_back({cx, cy});
    }

    // 每個群集分配點數
    vector<int> cluster_sizes(K, 0);
    for(int i=0; i<N; ++i) {
        cluster_sizes[rnd.next(0, K-1)]++;
    }

    // 每個群集生成點
    for(int i=0; i<K; ++i) {
        int cx = cluster_centers[i].first;
        int cy = cluster_centers[i].second;
        int size = cluster_sizes[i];
        for(int j=0; j<size; ++j) {
            // 在中心附近隨機偏移, 範圍可調
            int x = cx + rnd.wnext(-R, R, 2);
            int y = cy + rnd.wnext(-R, R, 2);
            cout << x << " " << y << '\n';
        }
    }

    int Q = rnd.next(20, 30);
    cout << Q << '\n';

    int op_sub = atoi(argv[1]);
    for (int i = 0; i < Q; ++i) {
        int op = (op_sub == 3 ? rnd.next(1, 2) : op_sub);
        int a = rnd.next(1, N);
        int b = rnd.next(1, N);
        while (b == a) b = rnd.next(1, N);
        cout << op << " " << a << " " << b << '\n';
    }

    return 0;
}
