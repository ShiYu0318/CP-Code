#include "testlib.h"
#include <iostream>

using namespace std;

bool in_range(int x, int y, int m, int n) { return (0 <= x && x < m && 0 <= y && y < n); }
//bool on_range(int x, int y, int m, int n) { return (0 < x && x <= m && 0 < y && y <= n); }


int main(int argc, char* argv[]) {
    // 初始化測資生成器
    registerGen(argc, argv, 1);

    // 讀取參數，設定測資範圍
    int K;
    // K = opt<int>(1);
    cin >> K;

    int M = rnd.next(3, K);
    int N = rnd.next(3, K);
    int h_min = 1;
    int h_max = 5000;


    cout << M << " " << N << '\n';

    vector<vector<int>> grid(M, vector<int>(N,h_max+1)), 
                        vis(M, vector<int>(N,0)), 
                        path_map(M, vector<int>(N,0));
    vector<pair<int,int>> path;

    // for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) cout << grid[i][j] << " \n"[j == N-1];
    // cout << '\n';
    // for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) cout << vis[i][j] << " \n"[j == N-1];
    // cout << '\n';


    int x = rnd.next(0, M-1), 
        y = rnd.next(0, N-1);
    int mx = x, my = y;
    // cout << x << " " << y << '\n';

    // 順時鐘：上 右上 右 右下 下 左下 左 左上 
    int dx[8] = {-1,-1,0,1,1,1,0,-1};
    int dy[8] = {0,1,1,1,0,-1,-1,-1};

    int h = h_max;
    int round = 1;
    int max_steps = M * N;  // 最多執行 M*N 步，避免無限迴圈
    while(round < max_steps)
    {
        //cout << round << " ---------------------------------------------------------\n";
        vis[x][y] = 1;
        path_map[x][y] = round;
        path.push_back({x,y});
        grid[x][y] = h;
        h -= rnd.next(1, max(0, (h - h_min) / 3) + 1);

        // 檢查八方是否能動 不能動就將目前位置設為終點（最小值）
        bool can_move = false;
        for (int i=0; i<8; ++i)
        {
            int nx = x+dx[i], 
                ny = y+dy[i];
            if(in_range(nx,ny,M,N) && !vis[nx][ny])
            {
                can_move = true;
                break;
            }
        }
        if(!can_move) 
        {
            //grid[x][y] = h_min;
            break;
        }

        // 可以動就隨機選一個可以走的方向
        int d, nx, ny;
        do
        {
            d = rnd.next(0, 7);
            if(d == 0) d = rnd.next(0, 7);
            nx = x + dx[d], 
            ny = y + dy[d];
            //cout << "d=" << d << '\n';
        }
        while(!in_range(nx,ny,M,N) || vis[nx][ny]);

        // 把上一步的八方設不能走 更新下一步
        for (int i=0; i<8; ++i)
        {
            int nx = x + dx[i], 
                ny = y + dy[i];
            if(in_range(nx,ny,M,N)) vis[nx][ny] = 1;
        }
        x = nx, y = ny;
        ++round;
    }

    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++)
    {
        if(path_map[i][j] == 0) grid[i][j] = rnd.next(h_max+1, h_max*2-1);
    }

    grid[mx][my] = h_max * 2;
    // 1/5 的機率保證不可能走到最低：把倒數第二個改成比倒數第三個大
    bool impossible = (rnd.next(0, 4) == 0);
    // cout << impossible << '\n';
    if(impossible)
    {
        pair<int,int> a = path[path.size()-2], // 倒數第二個
                    b = path[path.size()-3];   // 倒數第三個
        grid[a.first][a.second] = grid[b.first][b.second] + 1;
    }


    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) cout << grid[i][j] << " \n"[j == N-1];
    cout << '\n';
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) cout << vis[i][j] << " \n"[j == N-1];
    cout << '\n';
    for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) cout << path_map[i][j] << " \n"[j == N-1];
    cout << '\n';
    for(auto i:path) cout << i.first << " " << i.second << '\n';

    return 0;
}
