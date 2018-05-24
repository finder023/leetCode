//每个递归函数只匹配一个字母，有三种匹配防止，或者不动， 或者向其他方向移动，这样，就有5个移动方向
class Solution {
public:
    bool existpath(vector< vector<char> >& board, vector< vector<bool> >& isused, string& word, int st, int row, int col){
        bool cur;
        if(st == word.length())
            return true;
        if(word[st] != board[row][col] || isused[row][col])
            return false;
        else{
            isused[row][col] = true;
            if(row > 0 && (cur=existpath(board, isused, word, st+1, row-1, col)) == true){
                return true;
            }
            if(row < board.size() -1  && (cur=existpath(board, isused, word, st+1, row+1, col)) == true){
                return true;
            }
            if(col > 0 && (cur=existpath(board, isused, word, st+1, row, col-1)) == true){
                return true;
            }
            if(col < board[0].size() && (cur=existpath(board, isused, word, st+1, row, col+1)) == true){
                return true;
            }
            isused[row][col] = false;
            return false;
        }
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool cur;
        vector< vector<bool> > isused(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if((cur = existpath(board, isused, word, 0, i, j)) == true)
                    return true;
            }
        }
        return false;
        
    }
};
