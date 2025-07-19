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
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << '\n';
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

// AC

struct DSU 
{
    vi leader, rk;
    DSU(int n) : leader(2*n), rk(2*n, 0) { RPT(i,2*n) leader[i] = i; }
    int find(int x) { return leader[x] == x ? leader[x] : leader[x] = find(leader[x]); }
    void uni(int x, int y) 
    {
        x = find(x); y = find(y);
        if(x == y) return;
        if(rk[x] < rk[y]) leader[x] = y;
        else if(rk[x] > rk[y]) leader[y] = x;
        else{ leader[y] = x; rk[x]++; }
    }
};

struct Graph 
{
    int n, m;
    vector<pii> edges;
    Graph(int n, int m) : n(n), m(m) { edges.reserve(m); }
    void add(int u, int v) { edges.emplace_back(u-1, v-1); }
    vi sol() 
    {
        DSU ds(n);
        vi res;
        RPT(i,m)
        {
            int u = edges[i].F, v = edges[i].S;
            int u1 = u, u2 = u + n, v1 = v, v2 = v + n;
            if(ds.find(u1) == ds.find(v1) || ds.find(u2) == ds.find(v2)) continue;
            ds.uni(u1, v2); ds.uni(u2, v1);
            res.EB(i + 1);
        }
        return res;
    }
};

signed main() 
{
    ShiYu;
    int n, m; cin >> n >> m;
    Graph graph(n, m);
    RPT(i,m)
    {
        int u, v; cin >> u >> v;
        graph.add(u, v);
    }
    vi res = graph.sol();
    output(res);
}