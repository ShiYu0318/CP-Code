class Solution {    
// 20260101 3ms O(n) 大數加法
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1]++;
        for (int i = digits.size() - 1; i > 0; --i) {
            digits[i - 1] += digits[i] / 10;
            digits[i] %= 10;
        }
        if (digits[0] >= 10) {
            digits.emplace_back(0);
            for (int i = digits.size() - 1; i > 1; --i)
                digits[i] = digits[i - 1];
            digits[1] = digits[0] % 10;
            digits[0] = 1;
        }
        return digits;
    }
};

// 0ms
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
//         int i=digits.size()-1;
//         while(i >= 0 && digits[i] == 9) digits[i--] = 0;
//         if(i < 0) digits.insert(digits.begin(),1);
//         else digits[i]++;
//         return digits;
//     }
// };