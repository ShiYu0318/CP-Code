class Solution {
    // 20260403
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>> sub(k, vector<int>(k, 0));
        for(int i=0;i*2<k;++i) for(int j=0;j<k;++j) swap(grid[x+i][y+j], grid[x+(k-i-1)][y+j]);
        return grid;
    }
};