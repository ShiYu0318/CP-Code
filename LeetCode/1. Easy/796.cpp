class Solution {
    // 20260503
public:
    bool rotateString(string s, string goal) {
        // for(int i=0;i<s.size();++i)
        // {
        //     if(s.substr(i) + s.substr(0,i) == goal) return true;
        // }
        // return false;
        return (s.size() == goal.size()) && ((s+s).find(goal) != -1);
    }
};