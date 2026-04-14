class Solution {
    // 20260415
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        for(int i=0; start + i < nums.size() || start - i >= 0; ++i)
        {
            if(start + i < nums.size() && nums[start + i] == target) return i;
            if(start - i >= 0 && nums[start - i] == target) return i;
        }
        return 0;
    }
};