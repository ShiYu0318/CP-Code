class Solution {
    // 20260907
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st;
        for(int i:nums)
        {
            if(st.count(i)) return true;
            st.insert(i);
        }
        return false;
    }
};