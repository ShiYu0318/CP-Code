class Solution {
    // 20260507
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int r = boxGrid.size(), c = boxGrid[0].size();
        vector<vector<char>> rbox(c, vector<char>(r, '.'));
        for(int i=0; i<r; ++i)
        {
            boxGrid[i].emplace_back('*');
            for(int j=0, cnt=0; j <= c; ++j)
            {
                if(boxGrid[i][j] == '#') ++cnt;
                else if(boxGrid[i][j] == '*')
                {
                    if(j != c) rbox[j][r-1-i] = '*';
                    for(int k=0; k<cnt; ++k) rbox[j-k-1][r-1-i] = '#';
                    cnt = 0;
                }
            }
        }
        return rbox;
    }
};