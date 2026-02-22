class Solution {
    // 20260222 O(n) 二進位數字的最大距離
public:
    long long binaryGap(long long n) {
        long long digit = 0, ans = 0;
        string s;
        while(n)
        {
            s = char('0' + (n % 2)) + s;
            n /= 2;
            ++digit;
        }
        for(long long i=0; i < digit-1; ++i)
        {
            if(s[i] == '0') continue;
            for(long long j=i+1; j < digit; ++j)
            {
                if(s[j] == '1')
                {
                    ans = max(ans, j - i);
                    i = j-1;
                    break;
                }
            }
        }
        return ans;
    }
};