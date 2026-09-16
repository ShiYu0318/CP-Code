class Solution {
    // 20260915
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int ans = 0, i, j;
        for(i=0, j=0; j < s.size(); ++j)
        {
            if(mp[s[j]])
            {
                ans = max(ans, j-i);
                while(s[i] != s[j])
                {
                    --mp[s[i]];
                    ++i;
                }
                --mp[s[i]];
                ++i;
            }
            ++mp[s[j]];
        }
        ans = max(ans, j-i);
        return ans;
    }
};