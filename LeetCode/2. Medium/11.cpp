class Solution {
    // 20260915
    // Two pointer
    // 水容器
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        for(int l=0, r=heights.size()-1; l != r;)
        {
            ans = max(ans, min(heights[l], heights[r]) * (r - l));
            if(heights[l] < heights[r]) ++l;
            else --r;
        }
        return ans;
    }
};
