//两次折中查找
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        //find row
        int l = 0, r = m-1, mid = (l+r)/2;
        while(0 <= mid && mid < m-1){
            if(l > r)
                return false;
            if(matrix[mid][0] > target)
                r = mid - 1;
            else if (matrix[mid+1][0] <= target)
                l = mid + 1;
            else
                break;
            mid = (l+r)/2;
        }
        int row = mid;
        //find col
        l = 0, r = n-1, mid = (l+r)/2;
        while(0<=mid && mid < n){
            if(l > r)
                return false;
            if(matrix[row][mid] == target)
                return true;
            else if(matrix[row][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
            mid = (l+r)/2;
        }
        return false;
    }
};

//另一种简单的方法，效率高一点？？
class Solution {
public:
    int val(vector< vector<int> >& mat, int i){
        return mat[i / mat[0].size()][i%mat[0].size()];
    }
    //vector< vector<int> >& mat;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int s = m*n;
        
        int l = 0, r = s-1, mid = (l+r)/2;
        while(0<=mid && mid < s){
            if(l > r)
                return false;
            if(val(matrix, mid) == target)
                return true;
            if(val(matrix, mid) > target)
                r = mid - 1;
            else
                l = mid + 1;
            mid = (l+r)/2;
        }
        return false;
    }
};
