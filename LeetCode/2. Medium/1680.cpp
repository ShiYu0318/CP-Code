// class Solution {
// public:
//     int concatenatedBinary(int n) {
//         string s;
//         const int M = 1e9+7;
//         for(int i=0, j; i<n; ++i)
//         {
//             j = i+1;
//             string t;
//             while(j)
//             {
//                 t = char('0' + (j%2)) + t;
//                 j >>= 1;
//             }
//             s += t;
//         }
//         __int128 sum = 0;
//         for(int i=s.size()-1, j=0; i >= 0; --i,++j)
//         {
//             sum += (s[i] == '1' ? ((__int128)1 << j) : 0);
//             sum %= M;
//         }
//         // cout << s << ' ' << sum << '\n';
//         return sum;
//     }
// };

class Solution {
    // RETRY
public:
    int concatenatedBinary(int n) {
        const int M = 1e9 + 7;
        long long ans = 0;
        int bits = 0;
        for (int i = 1; i <= n; ++i) {
            // 如果 i 是 2 的次方，就代表多了一位
            if ((i & (i - 1)) == 0)
                ++bits;
            ans = ((ans << bits) % M + i) % M;
        }
        return ans;
    }
};