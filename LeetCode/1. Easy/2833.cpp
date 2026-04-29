class Solution {
    // 20260429
public:
    int furthestDistanceFromOrigin(string moves) {
        int d = 0, t = 0;
        for(char &i:moves)
        {
            if(i == 'L') --d;
            else if(i == 'R') ++d;
            else ++t;
        }
        return (d > 0 ? d + t : (d < 0 ? 0 - d + t : t));
    }
};