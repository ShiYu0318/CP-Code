#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

// DSU 裸題

vector<int> boss;

int Find(int x)
{
    return (boss[x] == x ? x : boss[x] = Find(boss[x]));
}

void Union(int x, int y)
{
    int a = Find(x), b = Find(y);
    if(a != b) boss[b] = a;
}

signed main()
{
    ShiYu;
    int n,m,q,x,y; cin >> n >> m >> q;
    boss.resize(n+5); iota(all(boss), 0);
    while(m--)
    {
        cin >> x >> y;
        Union(x,y);
    }
    while(q--)
    {
        cin >> x >> y;
        cout << (Find(x) == Find(y) ? ":)" : ":(") << '\n';
    }
}