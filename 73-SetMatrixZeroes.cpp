//这是一种比较投机的方法
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int flag = INT_MAX - 1;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j] == 0){
                    for(int k = 0; k<matrix.size(); ++k)
                        matrix[k][j] = matrix[k][j] == 0 ? 0:flag;
                    for(int k=0; k<matrix[i].size(); ++k)
                        matrix[i][k] = matrix[i][k] == 0 ? 0:flag;
                }
            }
        }
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j<matrix[0].size(); ++j){
                if(matrix[i][j] == flag){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};
