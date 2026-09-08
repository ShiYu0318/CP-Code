class Solution {
    // 20260907
    // 二維陣列 + 巢狀迴圈
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i)
        {
            bitset<10> ba, bb;
            for(int j=0; j<9; ++j)
            {
                if(board[i][j] != '.')
                {
                    if(ba[board[i][j]]) return false;
                    ba[board[i][j]] = 1;
                }
                if(board[j][i] != '.')
                {
                    if(bb[board[j][i]]) return false;
                    bb[board[j][i]] = 1;
                }
            }
        }
        for(int i=0; i<9; i+=3) for(int j=0; j<9; j+=3)
        {
            bitset<10> bc;
            for(int k=0; k<3; ++k) for(int l=0; l<3; ++l) 
            {
                if(board[i+k][j+l] != '.')
                {
                    if(bc[board[i+k][j+l]]) return false;
                    bc[board[i+k][j+l]] = 1;
                }
            }
        }
        return true;
    }
};
