class Solution {
    // 20260421
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size()-1, i, j;
        for(i=0; i <= n && colors[i] == colors[n]; ++i);
        for(j=n; i >= 0 && colors[j] == colors[0]; --j);
        return (colors[0] != colors[n] ? n : max(n-i, j));
    }
};