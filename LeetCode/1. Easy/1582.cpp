class Solution {
    // 20260304
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), ans = 0;
        vector<int> a(m, 0), b(n, 0);
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) a[i] += mat[i][j];
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) b[i] += mat[j][i];
        for (int i=0; i<m; ++i) for (int j=0; j<n; ++j) if (mat[i][j] && a[i] == 1 && b[j] == 1) ++ans;
        return ans;
    }
};