class Solution {
    // 20260915
    // 括號匹配
public:
    bool isValid(string s) {
        stack<char> sk;
        for(char i:s)
        {
            if(sk.empty() || i == '(' || i == '[' || i == '{') sk.push(i);
            else if((sk.top() == '(' && i == ')') || 
                    (sk.top() == '[' && i == ']') || 
                    (sk.top() == '{' && i == '}')) sk.pop();
            else return false;
        }
        return sk.empty();
    }
};
