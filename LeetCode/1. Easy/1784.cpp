class Solution { // 20260306
public:
    bool checkOnesSegment(string s) {
        bool b = true;
        for(int i=1; i<s.size(); ++i)
        {
            if(s[i] == '0') b = false;
            if(!b && s[i] == '1') return false;
        }
        return true;
    }
};