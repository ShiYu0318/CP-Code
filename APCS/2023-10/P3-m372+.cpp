#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define RPT(i,n) for(int i=0; i<n; ++i)

// 每種水管可以接的方向
map<char,vector<int>> cnct
{     // 上 下 左 右
    {'F',{0,1,0,1}},
    {'H',{0,0,1,1}},
    {'7',{0,1,1,0}},
    {'I',{1,1,0,0}},
    {'X',{1,1,1,1}},
    {'L',{1,0,0,1}},
    {'J',{1,0,1,0}},
    {'0',{0,0,0,0}}
};

const int N = 510,
        dx[4] = {-1,1,0,0},
        dy[4] = {0,0,-1,1};
            //  上 下 左 右

int n,m,ans = INT_MIN;
char tb[N][N];
bool vis[N][N];

// 判斷新座標是否在範圍內且未被走過
// 得過一次 WA 原因在於未檢查原水管與新水管連接方向是否匹配
// k ^ 1： 0 <-> 1 上下; 2 <-> 3 左右
// 位元運算比原本更快 63ms -> 35ms
bool valid(int x, int y, int k)
{
    return ((0 <= x && x < n && 0 <= y && y < m) && !vis[x][y] && cnct[tb[x][y]][k^1]);
}

int BFS(int i, int j)
{
    vector<pii> pipe;  // 這個連通塊的水管們
    pipe.EB(i,j);      // 初始水管 會往四面擴散
    vis[i][j] = true;   // 這行不能省 答案會多一
    int now = 0,nx,ny;
    while(now < pipe.size())
    {
        auto [x,y] = pipe[now++];
        RPT(k,4) if(cnct[tb[x][y]][k]) // 拿出這個水管所能連接的方向
        {   // 對可連接的水管方向判斷是否連通
            nx = x + dx[k];
            ny = y + dy[k];
            if(valid(nx,ny,k))
            {
                pipe.EB(nx,ny);
                vis[nx][ny] = true;
            }
        }
    }
    return now; // 被加進去的水管都屬於同一個連通塊
}

signed main()
{
    ShiYu;
    cin >> n >> m;
    RPT(i,n) RPT(j,m) cin >> tb[i][j];
    RPT(i,n) RPT(j,m)
    {   // 對每個沒被走過的水管做 BFS
        if(tb[i][j] == '0' || vis[i][j]) continue;
        int cnt = BFS(i,j);  // 計算這個水管所屬的連通塊大小
        ans = max(ans,cnt);  // 嘗試更新答案
    }
    cout << ans << endl;
}