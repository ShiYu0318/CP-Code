class Solution {
    // 20260907
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(int i:nums) ++mp[i];
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for(auto& i:mp) heap.push({i.second, i.first});
        while(heap.size() > k) heap.pop();
        while(!heap.empty())
        {
            ans.emplace_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
