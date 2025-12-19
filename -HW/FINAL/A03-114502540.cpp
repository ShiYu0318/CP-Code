#include <bits/stdc++.h>
using namespace std;

const int MN = 15;

int main()
{
    // 定義 dp[x][y][z] = 走到 x,y 的方法數 z = 1 上一步是往下
    // 轉移：
    int m,n; cin >> m >> n;
    int dp[MN][MN][2] = {0};
    for(int i=0; i <= m; ++i)
    {
        for(int j=0; j <= n; ++j)
        {
            if(i == 0 && j == 0) dp[i][j][0] = 1;
            else if(i == 0 && j == 1) dp[i][j][0] = 1;
            else if(i == 1 && j == 0) dp[i][j][1] = 1;
            else
            {
                dp[i][j][0] += dp[i][j-1][0]  + dp[i][j-1][1];
                if(j >= 2) dp[i][j][0] += dp[i][j-2][1] + dp[i][j-2][0];
                if(i != 0) dp[i][j][1] += dp[i-1][j][0];
            }
        }
    }

    cout << dp[m][n][0] + dp[m][n][1] << "\n";
}