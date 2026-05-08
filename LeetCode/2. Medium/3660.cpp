class Solution {
    // 20260508
    // Greedy prefix-max suffix-min
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), suf(n), ans(n);
        pre[0] = nums[0]; 
        suf[n-1] = nums[n-1];
        for(int i=1; i<n; ++i)
        {
            pre[i] = max(pre[i-1], nums[i]);
            suf[n-1-i] = min(suf[n-i], nums[n-1-i]);
        }
        ans[n-1] = pre[n-1];
        // merge
        for(int i=n-2; i>=0; --i)
        {
            if(pre[i] > suf[i+1]) ans[i] = ans[i+1];
            else ans[i] = pre[i];
        }
        return ans;
        // // WA: 只考慮到二段跳 三段以上無法處理
        // int n = nums.size(), mx = INT_MIN;
        // vector<pair<int, int>> vp;
        // vector<int> mxv(n);
        // for(int i=0; i<n; ++i)
        // {
        //     mx = max(mx, nums[i]);
        //     if(nums[i] < mx)
        //     {
        //         mxv[i] = mx;
        //         vp.emplace_back(nums[i], mxv[i]);
        //     }
        //     else mxv[i] = nums[i];
        // }
        // sort(vp.begin(), vp.end());
        // for(int i=0; i<n; ++i)
        // {
        //     auto it = lower_bound(vp.begin(), vp.end(), make_pair(nums[i], 0));
        //     while(it != vp.begin())
        //     {
        //         --it;
        //         if(it->second > mxv[i]) mxv[i] = it->second;
        //     }
        // }
        // return mxv;
    }
};