#include <bits/stdc++.h>
using namespace std;
#define int long long
#define RPT(i,n) for(int i=0;i<n;++i)
#define EB emplace_back

// CPE

const int N = 10005;
vector< vector<int> > v(N);
int vis[N];

int BFS(int z)
{
    int cnt = 0;
    if(vis[z]) return 0;
    queue<int> q;
    q.emplace(z);
    while(q.size())
    {
        int t = q.front(); q.pop();
        if(vis[t]) continue;
        vis[t] = 1; ++cnt;
        for(auto i:v[t]) if(!vis[i]) q.emplace(i);
    }
    return cnt;
}


signed main()
{
    int t; cin >> t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int n,m,l; cin >> n >> m >> l;
        int x,y,z;
        RPT(i,m)
        {
            cin >> x >> y;
            v[x].EB(y);
        }
        int ans = 0;
        RPT(i,l)
        {
            cin >> z;
            ans += BFS(z);
        }
        cout << ans << '\n';
    }
}