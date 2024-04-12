#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define ll long long
using namespace std;

signed main()
{
    ShiYu;
    ll n,m,q; cin >> n >> m >> q;
    set<pair<int,int>> s;
    pair<int,int> p;
    ll a,b,c,d;
    FOR(i,0,m)
    {
        cin >> a >> b;
        if(a > b) swap(a,b);
        p = make_pair(a,b);
        s.insert(p);
    }
    FOR(i,0,q)
    {
        cin >> c >> d;
        if(c > d) swap(c,d);
        p = make_pair(c,d);
        cout << (s.count(p) ? "yes" : "no") << "\n";
    }
}