#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define endl '\n'
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)

const int N = 1005, dx[4] = {-1,1,0,0}, dy[4] = {0,0,-1,1};
const string d = "DURL";
int tb[N][N], n, m; pii a,b;

bool in_range(int x, int y) { return (0 <= x && x < n && 0 <= y && y <= m); }

bool BFS()
{
    queue<pii> q; q.emplace(a); tb[a.F][a.S] = 1;
    while(!q.empty())
    {
        auto [x,y] = q.front(); q.pop();
        RPT(i,4)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(in_range(nx,ny) && tb[nx][ny] == 0)
            {
                tb[nx][ny] = tb[x][y] + 1;
                q.emplace(nx,ny);
            }
            if(nx == b.F && ny == b.S) return true;
        }
    } return false;
}

string review()
{
    string s; auto [x,y] = b;
    while(tb[x][y] != 1) RPT(i,4)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(in_range(nx,ny) && tb[nx][ny] == tb[x][y] - 1)
        {
            s += d[i]; // TLE : s = d[i] + s;
            x = nx, y = ny; break;
        }
    } return s;
}

signed main()
{
    ShiYu; cin >> n >> m;
    RPT(i,n) RPT(j,m)
    {
        char c; cin >> c;
        if(c == '#') tb[i][j] = -1;
        if(c == 'A') a = {i,j};
        if(c == 'B') b = {i,j};
    }
    if(BFS())
    {
        string path = review(); reverse(all(path));
        cout << "YES\n" << tb[b.F][b.S]-1 << endl << path << endl;
    }
    else cout << "NO\n";
}