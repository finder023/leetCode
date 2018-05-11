//思路还是递归，结果超时，转用动态规划
//

class Solution {
public:
    int uniquePaths(int m, int n) {
        int numPaths = 0;
        vector< vector<int> > record(m, vector<int>(n, 0));
        for(int i=0; i<m; ++i){
            record[i][n-1] = 1;
        }
        for(int j=0; j<n; ++j){
            record[m-1][j] = 1;
        }
        int tmp;
        
        for(int i = m-2; i>=0; --i){
            for(int j=n-2; j>=0; --j){
                tmp = 0;
                if(i < m-1)
                    tmp += record[i+1][j];
                if(j < n-1)
                    tmp += record[i][j+1];
                record[i][j] = tmp;
                
            }
        }
        return record[0][0];
    }
};
