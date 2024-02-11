#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

signed main()
{
    ShiYu;
    int n,s; cin >> n >> s;
    string x;
    int now = s,t,ans = 0;
    while(n--)
    {
        cin >> x;
        t = x[0] - '0';
        if(x[x.size()-1] == 'L') ++t;
        if(now < t)
        {
            now = s;
            ++ans;
        }
        now -= t;
    }
    cout << ans << "\n";
}
