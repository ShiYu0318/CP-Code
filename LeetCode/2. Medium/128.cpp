class Solution {
    // 20260915
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1, tmp = 1;
        for(int i=1; i<nums.size(); ++i)
        {
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] - 1 == nums[i-1]) ans = max(ans, ++tmp);
            else tmp = 1;
        }
        return ans;
    }
};
