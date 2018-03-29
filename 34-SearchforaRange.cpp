class Solution {
public:
    
    int bsearch(vector<int>& nums, int i, int j, int target){
        int mid;
        while(i <= j){
            mid = (i+j)/2;
            if(target > nums[mid]){
                i = mid + 1;
            }
            else if(target < nums[mid]){
                j = mid - 1;
            }
            else
                return mid;
        }
        return -1;
    }  
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int data[2] = {-1, -1};
        vector<int> result(data, data+2);
        if(nums.size() == 0)
            return result;
        int i = 0, j = nums.size()-1; //记住这里一定是nums.size()-1，由于这个问题错了好半天！！！！
        int r;
        
        if((r = bsearch(nums, i, j, target)) == -1)
            return result;
        i = r;
        j = r;
        while(j < nums.size() && nums[j] == target) ++j;
        while(i >= 0 && nums[i] == target) --i;
        
        result[0] = i+1;
        result[1] = j-1;
        
        return result;
    }
};
