class Solution { // 20260305
public:
    int minOperations(string s) {
        int a = 0, b = 0;
        bool c = true;
        for(int i=0; i<s.size(); ++i)
        {
            a += s[i] != (c ? '1': '0');
            b += s[i] != (!c ? '1': '0');
            c = !c;
        }
        return min(a, b);
    }
};