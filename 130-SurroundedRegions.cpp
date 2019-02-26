#include <vector>

using namespace std;


class Solution {
public:
    int brow, bcol;
    void solve(vector<vector<char>>& board) {
        brow = board.size();
        if (brow == 0)
            return;
        bcol = board[0].size();
        
        for (int i=0; i<brow; ++i) {
            if (board[i][0] == 'O')
                checkConnected(board, i, 0);
            if (board[i][bcol-1] == 'O')
                checkConnected(board, i, bcol-1);
        }
        
        for (int j=0; j<bcol; ++j) {
            if (board[0][j] == 'O')
                checkConnected(board, 0, j);
            if (board[brow-1][j] == 'O')
                checkConnected(board, brow-1, j);
        }
        
        for (int i=0; i<brow; ++i) {
            for (int j=0; j<bcol; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '1')
                    board[i][j] = 'O';
            }
        }
        
        
    }
    
    void checkConnected(vector<vector<char>> &board, int row, int col) {
        if (row < 0 || row >= brow)
            return;
        if (col < 0 || col >= bcol)
            return;
        
        if (board[row][col] == '1')
            return;
        if (board[row][col] == 'O') {
            board[row][col] = '1';
        
            checkConnected(board, row+1, col);
            checkConnected(board, row-1, col);
            checkConnected(board, row, col+1);
            checkConnected(board, row, col-1);
        }
            
    }
};

int main() {
    vector<vector<char>> board = {{'X', 'X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
    Solution su;
    su.solve(board);
    
}