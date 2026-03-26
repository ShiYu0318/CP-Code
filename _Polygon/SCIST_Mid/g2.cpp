#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    // 初始化測資生成器
    registerGen(argc, argv, 1);

    // int M = opt<int>(1);      // 地圖行數
    // int N = opt<int>(2);      // 地圖列數
    // int h_min = opt<int>(3);  // 最小高度
    // int h_max = opt<int>(4);  // 最大高度

    int M, N, h_min, h_max; cin >> M >> N >> h_min >> h_max;

    cout << M << " " << N << '\n';

    vector<vector<int>> grid(M, vector<int>(N, h_max));  // 先全部填滿 h_max
    vector<pair<int, int>> path; // 紀錄唯一解路徑

    // 隨機選擇最高點 (h_max) 和最低點 (h_min)
    int sx = rnd.next(0, M - 1);
    int sy = rnd.next(0, N - 1);
    int ex = rnd.next(0, M - 1);
    int ey = rnd.next(0, N - 1);

    while (sx == ex && sy == ey) {  // 確保起點終點不同
        ex = rnd.next(0, M - 1);
        ey = rnd.next(0, N - 1);
    }

    // 設定 h_max 和 h_min
    grid[sx][sy] = h_max;
    grid[ex][ey] = h_min;
    path.emplace_back(sx, sy);

    // 產生唯一的下降路徑
    int x = sx, y = sy;
    while (x != ex || y != ey) {
        vector<pair<int, int>> candidates;

        // 八方向 {dx, dy}
        int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && grid[nx][ny] == h_max) {
                candidates.emplace_back(nx, ny);
            }
        }

        if (candidates.empty()) break; // 不應該發生

        // 選擇一個隨機方向下降
        pair<int, int> next_pos = candidates[rnd.next(0, (int)candidates.size() - 1)];
        x = next_pos.first;
        y = next_pos.second;

        // 設定該點的高度
        grid[x][y] = h_min + (int)path.size();  // 讓它逐步遞減
        path.emplace_back(x, y);
    }

    // 確保唯一解的條件
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == h_max) {  // 不是在主路徑上的點
                grid[i][j] = rnd.next(h_min + 1, h_max - 1);
            }
        }
    }

    // 輸出最高點與最低點位置
    cout << sx << " " << sy << '\n';
    cout << ex << " " << ey << '\n';

    // 輸出地圖
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " \n"[j == N - 1];
        }
    }

    // 1/5 的機率保證不可能走到最低：把倒數第二個改成比倒數第三個大
    
    return 0;
}
