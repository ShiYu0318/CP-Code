class Solution {
    // 20260418
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        int nn = stoi(s);
        return abs(n - nn);
    }
};