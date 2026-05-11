class Solution {
    // 20260511
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int i : nums)
        {
            string s = to_string(i);
            for(char j : s)
            {
                ans.emplace_back(j - '0');
            }
        }
        return ans;
    }
};