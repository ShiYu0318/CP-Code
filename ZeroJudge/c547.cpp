#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7, N = 10005;
int dp[N];

int main()
{
    dp[0] = dp[1] = 1;
    for(int i=2; i<=N; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    
    int n;
    while(cin >> n)
    {
        cout << dp[n] << "\n";
    }
}