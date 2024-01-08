#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define YN(x) cout << (x ? "Yes" : "No") << "\n";
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
using namespace std;

const ll MOD = 1e9+7;

signed main()
{
    ShiYu
    ll n; cin >> n;
    ll dp[n];
    dp[0] = 0;
    FOR(i,1,n)
    {
        FOR(j,1,7)
        {
            dp[i] += dp[i-j];
        }
    }
}