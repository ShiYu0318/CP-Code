#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.rbegin(),x.rend()
#define int long long
#define F first
#define S second

// greedy

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> v(n); input(v);
    sort(all(v));
    int ans = 0, t = n / 2;
    RPT(i,n)
    {
        if(i<t) ans += v[i];
        else ans += v[i] / 2;
    }
    cout << ans << "\n";
}
