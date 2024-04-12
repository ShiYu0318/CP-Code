#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// complexity 觀察性質

signed main()
{
    ShiYu;
    int a,b,c,x,y; cin >> a >> b >> c >> x >> y;
    int ans;
    if(a+b >= 2*c)
    {
        int n = min(x,y) * 2 * c;
        if(x > y) n += (x - y) * a;
        else if(x < y) n += (y - x) * b;
        int m = max(x,y) * 2 * c;
        ans = min(n,m);
    }
    else ans = a * x + b * y;
    cout << ans << "\n";
}
