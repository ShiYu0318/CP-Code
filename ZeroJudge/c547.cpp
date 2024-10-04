#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main()
{
    int n, dp[10005];
    dp[0] = dp[1] = 1;
    while(cin >> n)
    {
        for(int i=2; i<=n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;
        }
        cout << dp[n] << "\n";
    }
}