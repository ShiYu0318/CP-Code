class Solution { // 20260325
public:
    bool same(vector<vector<int>>& a, vector<vector<int>>& b, int n)
    {
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(a[i][j] != b[i][j]) return false;
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        vector<vector<int>> tmp(n, vector<int>(n, 0));
        if(same(mat, target, n)) return true;
        for(int k=0;k<3;++k)
        {
            for(int i=0;i<n;++i) for(int j=0;j<n;++j) tmp[i][j] = mat[n-j-1][i];
            for(int i=0;i<n;++i) for(int j=0;j<n;++j) mat[i][j] = tmp[i][j];
            if(same(mat, target, n)) return true;
        }
        return false;
    }
};