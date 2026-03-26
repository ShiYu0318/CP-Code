#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int subtask = atoi(argv[1]);    // 1: 難題、2: 暴力可過
    int difficulty = atoi(argv[2]); // 控制正數區域密度（推薦 1～5）

    int N, M;

    if (subtask == 2) {
        N = rnd.next(20, 50);
        M = rnd.next(20, 50); // 小矩陣，暴力可行
    } else {
        N = rnd.next(450, 500); 
        M = rnd.next(450, 500); // 大矩陣，需最佳化
    }

    cout << N << " " << M << '\n';

    vector<vector<int>> mat(N, vector<int>(M));

    // 全部設為隨機負數（確保不能貪心）
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            mat[i][j] = rnd.next(-10000, -1);

    // 加入一塊正整數區域（模擬最大子矩陣）
    int size_range = (subtask == 2 ? 10 : 50); // 小題可塞小區域，大題塞大區域
    int r1 = rnd.next(0, N - size_range * 2);
    int r2 = r1 + rnd.next(size_range, size_range * 2);
    int c1 = rnd.next(0, M - size_range * 2);
    int c2 = c1 + rnd.next(size_range, size_range * 2);

    for (int i = r1; i < r2; ++i) {
        for (int j = c1; j < c2; ++j) {
            if (rnd.next(100) < 20 * difficulty) // 密度高會更簡單
                mat[i][j] = rnd.next(1, 10000);
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
