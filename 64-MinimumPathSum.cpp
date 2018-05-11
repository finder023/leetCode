//还是动态规划的题
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector< vector<int> > record(m, vector<int>(n, 0));
        record[m-1][n-1] = grid[m-1][n-1];
        int tmp1, tmp2, tmp;
        
        for(int i=m-1; i>=0; --i){
            for(int j=n-1; j>=0; --j){
                tmp1 = INT_MAX;
                tmp2 = INT_MAX;
                if(i < m-1)
                    tmp1 = record[i+1][j];
                if(j < n-1)
                    tmp2 = record[i][j+1];
                if(i == m-1 && j == n-1) continue;
                record[i][j] = grid[i][j] + min(tmp1, tmp2); 
            }
        }
        return record[0][0];
    }
};
