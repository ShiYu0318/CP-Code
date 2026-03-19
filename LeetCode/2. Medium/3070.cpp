class Solution {
    // 20260319
    // 二維前綴和
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int r = grid.size(), c = grid[0].size(), cnt = 0;
        vector<vector<int>> pre(r+1, vector<int>(c+1, 0));
        for(int i=0; i<r; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + grid[i][j];
                if(pre[i+1][j+1] <= k) ++cnt;
            }
        }
        return cnt;
    }
};