class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector< vector<int> > matrix(n, vector<int>(n, 0));
        vector< vector<bool> > mtag(n, vector<bool>(n, false));
        
        int pirority = 3;
        int index = 0;
        int i=0, j=0;
        while(index < n*n){
            switch (pirority) {
                case 3: {
                    while (j < matrix[0].size() && !mtag[i][j]) {
                        matrix[i][j] = ++index;
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
                        matrix[i][j] = ++index;
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
                        matrix[i][j] = ++index;
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
                        matrix[i][j] = ++index;
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
        return matrix;
        
    }
};
