class Solution {
public:
    int trap(vector<int>& height) {
        int high, left;
        int counth = 0;
        int num = 0;
        bool match = false;
        for(high = 1; ;++high){
            left = -1;
            counth = 0;
            for(int i=0; i<height.size(); ++i){
                if(height[i] >= high){
                    ++counth;
                    if(i - left == 1){
                        left = i;
                        continue;
                    }
                    if(left != -1){
                        num += (i - left - 1);
                    }
                    left = i;
                }
            }
            if(counth < 2)
                break;
        }
        return num;
        
    }
};

//这段代码方法是正确的，但是运行时间超时了
class Solution {
public:
    int trap(std::vector<int>& A) {
        int n = A.size();
        int left=0; int right=n-1;
        int res=0;
        int maxleft=0, maxright=0;
        while(left<=right){
            if(A[left]<=A[right]){
                if(A[left]>=maxleft) maxleft=A[left];
                else res+=maxleft-A[left];
                left++;
            }
            else{
                if(A[right]>=maxright) maxright= A[right];
                else res+=maxright-A[right];
                right--;
            }
        }
        return res;
    }
};
