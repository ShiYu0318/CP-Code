class Solution {
public:
    bool isPalindrome(string s) {
        string ss;
        for(char c:s)
        {
            if(('a' <= c && c <= 'z') || ('0' <= c && c <= '9')) ss += c;
            else if('A' <= c && c <= 'Z') ss += 'a' + (c - 'A');
        }
        
        for(int i=0, j=ss.size()-1; i<ss.size(); ++i, --j)
        {
            if(ss[i] != ss[j]) return false;
        }
        return true;
    }
};
