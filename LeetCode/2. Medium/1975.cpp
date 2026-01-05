class Solution {    // 20260105
public:     // 無限次操作 最後只會剩下 0 或 1 個負數 那個負數可以轉移到最小絕對值
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0, mi = INT_MAX, cnt = 0;
        for(auto i:matrix)
        {
            for(long long j:i)
            {
                sum += abs(j);
                mi = min(mi, abs(j));
                if(j < 0) ++cnt;
            }
        }
        return (cnt & 1 ? sum - mi*2 : sum);
    }
};