class Solution 
{
    // 20260430
    // 3D/2D 背包 grid DP
public:
    int maxPathScore(vector<vector<int>>& grid, int k) 
    {
        // define: dp[i][j][k] = max sum of reaching (x, y) and cost = k
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, -1)));
        
        // init
        bool b = (grid[0][0] > 0);
        if(b <= k) dp[0][0][b] = grid[0][0];
        // dp[i][0]
        for(int i=1; i<m; ++i)
        {
            bool b = (grid[i][0] > 0);
            for(int c=b; c<=k; ++c)
            {
                if(dp[i-1][0][c-b] != -1) dp[i][0][c] = dp[i-1][0][c-b] + grid[i][0];
            }
        }
        // dp[0][j]
        for(int j=1; j<n; ++j)
        {
            bool b = (grid[0][j] > 0);
            for(int c=b; c<=k; ++c)
            {
                if(dp[0][j-1][c-b] != -1) dp[0][j][c] = dp[0][j-1][c-b] + grid[0][j];
            }
        }

        // transition
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
            {
                bool b = (grid[i][j] > 0);
                for(int c=b; c<=k; ++c)
                {
                    int pre = max(dp[i-1][j][c-b], dp[i][j-1][c-b]);
                    if(pre != -1) dp[i][j][c] = pre + grid[i][j];
                }
            }
        }

        // ans
        int ans = -1;
        for(int i=0; i<=k; ++i) ans = max(ans, dp[m-1][n-1][i]);
        return ans;
    }
};