class Solution {
    // 20260915
    // Leetcode 高級會員題 / NeetCode Blind 75
public:

    string encode(vector<string>& strs) {
        string s;
        for(string ss:strs) s += ss + '\n';
        return s;
    }

    vector<string> decode(string s) {
        vector<string> v;
        for(int i=0, j=0;i<s.size();++i)
        {
            if(s[i] == '\n')
            {
                v.emplace_back(s.substr(j,i-j));
                j = i+1;
            }
        }
        return v;
    }
};
