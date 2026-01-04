#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    int dp[31][31] = {0};
    dp[0][0] = 1;
    for(int i=1; i<n; i++) dp[0][i] = 0;
    for(int i=1; i<=m; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j] = dp[i-1][(j+1)%n] + dp[i-1][(j-1+n)%n];
        }
    }
    cout << dp[m][0] << '\n';
}


// 遞迴 stack overflow
// #include <bits/stdc++.h>
// using namespace std;

// int n, m;

// // 經過 i 次傳球 球在 j 手上
// int f(int i, int j)
// {
//     if(i == m) return (j == 0);
//     return f(i+1, (j+1)%n) + f(i+1, (j-1+n)%n);
// }

// int main()
// {
//     cin >> n >> m;
//     cout << f(0,0) << '\n';
// }