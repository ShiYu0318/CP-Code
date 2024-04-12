#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)


signed main()
{
	ShiYu;
    int n; cin >> n;
    int dp[11]={};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    if(n > 3)
    {
        FOR(i,4,n+1)
        {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
    }
    cout << dp[n] << "\n";
	return 0;
}