#include <bits/stdc++.h>
using namespace std;

// 建表 8 個移動方向
//        0  1   2  3   4  5   6  7
// 順時鐘：上 右上 右 右下 下 左下 左 左上 
const int dx[8] = {-1,-1,0,1,1,1,0,-1};
const int dy[8] = {0,1,1,1,0,-1,-1,-1};
const string ds[8] = {"U","UR","R","DR","D","DL","L","UL"};

vector<vector<int>> grid;
int m, n;
string path;

// 判斷是否在圖尺寸範圍中
bool in_range(int x, int y) { return (0 <= x && x < m && 0 <= y && y < n); }

// 從最高點走到最低點
bool GD(pair<int, int> max_pos, pair<int, int> min_pos)
{
    int x = max_pos.first, y = max_pos.second;

    while (make_pair(x, y) != min_pos) 
    {
        int best_d = -1;
        int min_height = grid[x][y];

        // 遍歷 8 個方向，找到最低的鄰居
        for (int i=0; i<8; ++i) 
        {
            int nx = x + dx[i], 
                ny = y + dy[i];
            if (in_range(nx,ny) && grid[nx][ny] < min_height) 
            {
                min_height = grid[nx][ny];
                best_d = i;
                
            }
        }

        // 如果八方都不能走就無法走到最低點
        if (best_d == -1) return false;
        path += ds[best_d] + "+";
        x += dx[best_d];
        y += dy[best_d];
    }

    return true;
}

int main()
{
    cin >> m >> n;
    grid.resize(m, vector<int>(n));

    int max_h = -1, min_h = INT_MAX;
    pair<int, int> max_pos, min_pos;

    // 讀入二維圖並記錄最大最小值
    for (int i = 0; i < m; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            cin >> grid[i][j];
            if (grid[i][j] > max_h) 
            {
                max_h = grid[i][j];
                max_pos = {i, j};
            }
            if (grid[i][j] < min_h) 
            {
                min_h = grid[i][j];
                min_pos = {i, j};
            }
        }
    }
    bool ans = GD(max_pos, min_pos);
    if(ans)
    {
        cout << "YES\n";
        path.pop_back();
        cout << path << '\n';
    }
    else cout << "NO\n";
}