#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <subtask_id>\n";
        return 1;
    }

    int subtask = atoi(argv[1]); // 1~3
    int difficulty = 50;         // 熱區內正數密度百分比

    int N, M;
    int neg_min = -10000, neg_max = -1;
    int pos_min = 1, pos_max = 10000;

    // 根據子題設定 N, M 上限
    if (subtask == 1) {         // 六層暴力可過
        N = rnd.next(5, 30);
        M = rnd.next(5, 30);
    } else if (subtask == 2) {  // 前綴和可過
        N = rnd.next(80, 150);
        M = rnd.next(80, 150);
    } else {                    // Kadane 最佳化
        N = rnd.next(450, 500);
        M = rnd.next(450, 500);
    }

    cout << N << " " << M << '\n';

    vector<vector<int>> mat(N, vector<int>(M));

    // 先填滿隨機負數（確保不能用貪心找全正矩陣）
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            mat[i][j] = rnd.next(neg_min, neg_max);

    // 插入一塊正整數熱區
    int size_range;
    if (subtask == 1) size_range = max(2, N / 4);    // 小一點
    else if (subtask == 2) size_range = max(5, N / 6);
    else size_range = max(30, N / 10);               // 大一點

    int r1 = rnd.next(0, N - size_range * 2);
    int r2 = min(N, r1 + rnd.next(size_range, size_range * 2));
    int c1 = rnd.next(0, M - size_range * 2);
    int c2 = min(M, c1 + rnd.next(size_range, size_range * 2));

    for (int i = r1; i < r2; ++i) {
        for (int j = c1; j < c2; ++j) {
            if (rnd.next(100) < difficulty) {
                mat[i][j] = rnd.next(pos_min, pos_max);
            }
        }
    }

    // 輸出
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << mat[i][j] << " \n"[j == M - 1];
        }
    }

    return 0;
}
