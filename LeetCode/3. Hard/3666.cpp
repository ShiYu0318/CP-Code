class Solution {
    // 20260227
    // RETRY
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int m = count(s.begin(), s.end(), '0');
        if (m == 0) return 0;

        int start_t = (m + k - 1) / k;
        for (int t = start_t; t <= n; ++t) {
            long long S = 1LL * t * k;
            if (S < m) continue;
            if ((S - m) % 2 != 0) continue;
            long long cap = 1LL * m * ((t - 1) / 2) + 1LL * (n - m) * (t / 2);
            long long need = (S - m) / 2;
            if (need <= cap) return t;
        }
        return -1;
    }
};