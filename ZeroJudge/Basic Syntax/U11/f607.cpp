#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

signed main()
{
    ShiYu;
    int n,L; cin >> n >> L;
    vector<int> v(n);
    int x,i;
    while(n--)
    {
        cin >> x >> i;
        v[i-1] = x;
    }
    set<int> s;
    s.insert(0); s.insert(L);
    int ans = 0;
    for(auto i:v)
    {
        s.insert(i);
        auto it = s.find(i);
        ans += *next(it) - *prev(it);
    }
    cout << ans << "\n";
}
