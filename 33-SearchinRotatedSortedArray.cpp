//两次二分搜索

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
    
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int i = 0;
        while(i<nums.size()-1 && nums[i] <= nums[i+1]) ++i;
        if(i == nums.size() - 1)
            return bsearch(nums, 0, nums.size()-1, target);
        else 
            return max(bsearch(nums, 0, i, target), bsearch(nums, i+1, nums.size()-1, target));
    }
};
