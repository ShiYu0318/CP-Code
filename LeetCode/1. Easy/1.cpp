class Solution {
    // 20260907
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        vector<int> ans;
        for(int i=0; i< nums.size(); ++i)
        {
            if(!mp.empty() && mp.count(target - nums[i])) 
            {
                ans = {mp[target - nums[i]], i};
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};