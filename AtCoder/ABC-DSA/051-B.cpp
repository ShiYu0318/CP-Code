#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
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

// 枚舉

signed main()
{
    ShiYu
    int k,s; cin >> k >> s;
    int ans = 0;
    RPT(i,k+1)
    {
        RPT(j,k+1)
        {
            if(s - i - j <= k && i + j <= s) ++ans;
        }
    }
    cout << ans << "\n";
}
