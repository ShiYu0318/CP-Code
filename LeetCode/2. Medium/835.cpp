class Solution {
    // 20260914
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> v1, v2;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(img1[i][j]) v1.emplace_back(make_pair(i,j));
                if(img2[i][j]) v2.emplace_back(make_pair(i,j));
            }
        }
        vector<int> cnt(4 * n * n, 0);
        int ans = 0;
        for(pair<int,int> i:v1)
        {
            for(pair<int,int> j:v2)
            {
                int dx = i.first - j.first + n,
                    dy = i.second - j.second + n;
                ans = max(ans, ++cnt[dx * 2 * n + dy]);
            }
        }
        return ans;
    }
};