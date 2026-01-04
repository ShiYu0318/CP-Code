class Solution {    // 20260104 22ms
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(int i:nums)
        {
            int cnt = 2, sum = i + 1;
            for(int j = 2; j * j <= i; ++j)
            {
                if(i % j == 0)
                {
                    ++cnt; sum += j;
                    if(j != i/j)
                    {
                        ++cnt;
                        sum += i / j;
                    }
                }
            }
            if(cnt == 4) ans += sum;
        }
        return ans;
    }
};

// class Solution {     // AI：質數 7ms
// public:
//     int sumFourDivisors(vector<int>& nums) {
//         const int MAXV = 100000;
//         vector<bool> isPrime(MAXV + 1, true);
//         isPrime[0] = isPrime[1] = false;
//         for (int i = 2; i * i <= MAXV; ++i)
//             if (isPrime[i])
//                 for (int j = i * i; j <= MAXV; j += i)
//                     isPrime[j] = false;
        
//         int ans = 0;
//         for (int x : nums) {
//             int sum = 0;
//             // case 1: x = p^3
//             int p = round(pow(x, 1.0/3));
//             if (p * p * p == x && p >= 2 && isPrime[p]) {
//                 sum = 1 + p + p*p + p*p*p;
//             }
//             else {
//                 // case 2: x = p*q
//                 for (int p = 2; p * p <= x; ++p) {
//                     if (x % p == 0) {
//                         int q = x / p;
//                         if (q != p && q <= MAXV && isPrime[p] && isPrime[q]) {
//                             sum = 1 + p + q + x;
//                         }
//                         break; // 只需檢查一組因數
//                     }
//                 }
//             }
//             ans += sum;
//         }
//         return ans;
//     }
// };