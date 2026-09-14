class Solution {
    // 20260915
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre_sum = 1, suf_sum = 1, n = nums.size();
        vector<int> pre{1},suf{1}, ans;
        for(int i=0; i<n; ++i) 
        {
            pre_sum *= nums[i];
            pre.emplace_back(pre_sum);
            suf_sum *= nums[n-i-1];
            suf.emplace_back(suf_sum);
        }
        for(int i=0;i<n;++i) ans.emplace_back(pre[i] * suf[n-i-1]);
        return ans;
    }
};
