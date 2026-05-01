class Solution {
    // 20260502
    // F(k) = F(k-1) + sum - nums[n-k] * n
public:
    int maxRotateFunction(vector<int>& nums) {
        int now = 0, sum = 0, n = nums.size();
        for(int i=0; i<n; ++i)
        {
            now += i * nums[i];
            sum += nums[i];
        }
        int mx = now;
        for(int i=1; i<n; ++i)
        {
            now = now + sum - nums[n-i] * n;
            mx = max(mx, now);
        }
        return mx;
    }
};