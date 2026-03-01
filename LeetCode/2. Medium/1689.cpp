class Solution {
    // 20260301
    // RETRY
public:
    int minPartitions(string n) {
        char maxDigit = '0';
        for (char c : n)
            if (c > maxDigit)
                maxDigit = c;
        return maxDigit - '0';
    }
};