// 2026-01-02 0ms
class Solution {
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