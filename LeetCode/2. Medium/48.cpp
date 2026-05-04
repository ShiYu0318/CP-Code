class Solution {
    // 20260504
    // transpose + reverse
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(i > j) continue;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j*2 < n; ++j)
            {
                swap(matrix[i][j], matrix[i][n-1-j]);
            }
        }
    }
};