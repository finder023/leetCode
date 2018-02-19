/*
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.

*/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int tag;
        
        for(int j=0; j<cols; ++j){
            tag = matrix[0][j];
            for(int k=0; k<rows && j+k<cols; ++k){
                if(tag != matrix[k][j+k])
                    return false;
            }
            
        }
        
        for(int i=1; i<rows; ++i){
            tag = matrix[i][0];
            for(int k=0; k<cols && k+i<rows; ++k){
                if(tag != matrix[k+i][k])
                    return false;
            }
        }
        return true;
    }
};
