class Solution {
    // 20260418
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        for(int i=0; i*2 <= words.size(); ++i)
        {
            if(words[(startIndex + i) % words.size()] == target || words[(startIndex - i + words.size()) % words.size()] == target) return i; 
        }
        return -1;
    }
};