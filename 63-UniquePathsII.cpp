//还是冬天规划算法，不过相比上一题改了一点

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] || obstacleGrid[0][0]) return 0;
        
        vector< vector<int> > record(m, vector<int>(n, 0));
       
        record[m-1][n-1] = 1;
        int tmp;
        
        for(int i = m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                if (obstacleGrid[i][j])    continue;
                tmp = 0;
                if(i < m-1)
                    tmp += record[i+1][j];
                if(j < n-1)
                    tmp += record[i][j+1];
                record[i][j] = tmp > record[i][j] ? tmp : record[i][j];
                
            }
        }
        return record[0][0];
    }
};
