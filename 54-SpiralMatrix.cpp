class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return vector<int>();
        vector<bool> tmp(matrix[0].size(), false);
        vector< vector<bool> > mtag(matrix.size(), tmp);
        
        int pirority = 3;
        int index = 0;
        int i=0, j=0;
        vector<int> result(matrix.size()*matrix[0].size(), 0);
        while(index < result.size()){
            switch (pirority) {
				case 3: {
					while (j < matrix[0].size() && !mtag[i][j]) {
						result[index++] = matrix[i][j];
						mtag[i][j] = true;
						++j;
					}
					--j;
					--pirority;
					++i;
					break;
				}
				case 2: {
					while (i < matrix.size() && !mtag[i][j]) {
						result[index++] = matrix[i][j];
						mtag[i][j] = true;
						++i;
					}
					--i;
					--pirority;
					--j;
					break;
				}
				case 1: {
					while (j >= 0 && !mtag[i][j]) {
						result[index++] = matrix[i][j];
						mtag[i][j] = true;
						--j;
					}
					++j;
					--pirority;
					--i;
					break;
				}
				case 0: {
					while (i >=0 && !mtag[i][j]) {
						result[index++] = matrix[i][j];
						mtag[i][j] = true;
						--i;
					}
					++i;
					pirority = 3;
					++j;
					break;
				}
			}
        }
        return result;
    }
};
