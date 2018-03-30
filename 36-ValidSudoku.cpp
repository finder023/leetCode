class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool markrow[9][9], markcol[9][9], markrect[9][9];
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                markrow[i][j] = false;
                markcol[i][j] = false;
                markrect[i][j] = false;
            }
        }
        int index;
        int recti, rectj;
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.')
                    continue;
                index = board[i][j] - '0' - 1;
                recti = (i/3)*3+(j/3);
                if(markrow[i][index] || markcol[j][index] || markrect[recti][index])
                    return false;
                markrow[i][index] = true;
                markcol[j][index] = true;
                markrect[recti][index] = true;
            }
        }
        return true;
    }
};
