class Solution {
// 20260418
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int mi = INT_MAX;
        for(int i=0; i<nums.size(); ++i)
        {
            if(mp.count(nums[i])) mi = min(mi, i - mp[nums[i]]);
            string s = to_string(nums[i]);
            while(s.back() == '0') s.pop_back();
            reverse(s.begin(), s.end());
            mp[stoi(s)] = i;
        }
        return (mi != INT_MAX ? mi : -1);
    }
};