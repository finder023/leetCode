#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;
        int cols = triangle.size();
        vector<int> record(triangle[cols-1].begin(), triangle[cols-1].end());
        
        for (int i=cols-2; i>=0; --i) {
            for (int j=0; j<=i; ++j) {
                record[j] = (record[j] < record[j+1] ? record[j] : record[j+1]) + triangle[i][j];
            }
        }
        return record[0];
    }
};

int main() {
    vector<vector<int>> triangle;
    int buff[] = {2,3,4,6,5,7,4,1,8,3};
    int *ptr = buff;
    for (int i=1; i<=4; ++i) {
        triangle.push_back(vector<int>(ptr, ptr+i));
        ptr += i;
    }
    
    Solution su;
    int res = su.minimumTotal(triangle);

    return 0;
   
}