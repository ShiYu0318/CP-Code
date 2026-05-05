// class Solution {
//     // 20260505
//     // 枚舉 O(n log n)
//     // 
// public:
//     int rotatedDigits(int n) {
//         int cnt = 0;
//         for(int i=1; i<=n; ++i)
//         {
//             string s = to_string(i);
//             bool b = false;
//             for(int j=0; j<s.size(); ++j)
//             {
//                 if(s[j] == '3' || s[j] == '4' || s[j] == '7') 
//                 {
//                     b = false;
//                     break;
//                 }
//                 else if(s[j] == '2' || s[j] == '5' || s[j] == '6' || s[j] == '9') b = true;
//             }
//             if(b) ++cnt;
//         }
//         return cnt;
//     }
// };

class Solution {
    // DP O(n)
    // 位數前綴
public:
    int rotatedDigits(int n) {
        vector<int> dp(n+1, 0);
        int cnt = 0;
        for(int i=0; i<=n; i++)
        {
            if(i < 10)
            {
                switch(i)
                {
                    case 0: case 1: case 8:
                        dp[i] = 1; break;
                    case 2: case 5: case 6: case 9:
                        dp[i] = 2; ++cnt; break;
                    default: 
                        dp[i] = 0;
                }
            }
            else
            {
                int a = dp[i / 10], b = dp[i % 10];
                if(a == 1 && b == 1) dp[i] = 1;
                else if(a >= 1 && b >= 1) { dp[i] = 2; ++cnt; }
                else dp[i] = 0;
            }
        }
        return cnt;
    }
};