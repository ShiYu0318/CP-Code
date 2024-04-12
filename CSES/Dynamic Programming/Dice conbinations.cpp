#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YN(x) cout << (x ? "Yes" : "No") << '\n';
#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

const int MOD = 1e9+7,MAXN=1e6+5;
int dp[MAXN];

signed main()
{
    ShiYu;
    int n; cin >> n;
    dp[0] = 1;
    FOR(i,1,n+1)
    {
        for(int j=1;j <= min(i,(long long)6); ++j)
        {
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }
    cout << dp[n];
}