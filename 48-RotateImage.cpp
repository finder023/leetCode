class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n < 2)
            return;
        int temp, tempn;
        int x;
        for(int i=0; i<n/2; ++i){
            for(int j=i; j<n-i-1; ++j){
                int ii = i, jj = j;
                temp = matrix[i][j];
                for(int k=0; k<4; ++k){
                    tempn = matrix[jj][n-ii-1];
                    matrix[jj][n-ii-1] = temp;
                    temp = tempn;
                    x = jj;
                    jj = n-ii-1;
                    ii = x;
                }
            }
        }
        
    }
};

//这是不用太多额外空间的方法，本质上就是把列转成行就行了
