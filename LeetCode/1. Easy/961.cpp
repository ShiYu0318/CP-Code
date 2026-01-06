class Solution {    
// 20260102 0ms O(n)
// 用 bucket 找重複 + bitset 優化
public:
    int repeatedNTimes(vector<int>& nums) {
        bitset<10005> bs;
        for(auto i : nums)
        {
            if(bs[i]) return i;
            else bs[i] = 1;
        }
        return 0;
    }
};