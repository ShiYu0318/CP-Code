class Solution {
    // 20260226
public:
    int numSteps(string s) {
        int cnt = 0;
        while(s != "1")
        {
            if(s.back() == '0') s.pop_back();
            else
            {
                int i = s.size()-1;
                while(i >= 0 && s[i] != '0') s[i--] = '0';
                if(i<0) s = '1' + s;
                else s[i] = '1';
                cout << s << "\n";
            }
            ++cnt;
        }
        return cnt;
    }
};

// class Solution {
// public:
//     int numSteps(string s) {
//         int num = 0, bit = 1, cnt = 0;
        
//         for(int i = s.size()-1; i >= 0; --i)
//         {
//             if(s[i] == '1') num += bit;
//             bit <<= 1;
//         }

//         while(num != 1)
//         {
//             if(num % 2) ++num;
//             else num >>= 1;
//             ++cnt;
//         }
//         return cnt;
//     }
// };