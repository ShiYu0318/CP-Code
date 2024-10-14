#include <bits/stdc++.h>
using namespace std;

const int N = 30005, coins[5] = {1,5,10,25,50};
long long dp[N];

int main()
{
    dp[0] = 1;
    for(int i=0; i<5; i++)
    {
        for(int j=coins[i]; j<=N; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

    int n;
    while(cin >> n)
    {
        if(dp[n] == 1) cout << "There is only 1 way";
        else cout << "There are " << dp[n] << " ways";
        cout << " to produce " << n << " cents change.\n";
    }
}