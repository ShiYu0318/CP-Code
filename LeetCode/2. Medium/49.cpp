class Solution {
    // 20260915
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(string s:strs)
        {
            string ss = s;
            sort(ss.begin(), ss.end());
            mp[ss].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto i:mp) ans.emplace_back(i.second);
        return ans;
    }
};
