//设两个指针，一个记录已扫描位置，一个记录排序好的位置，
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0;
        int len = 0;
        int cur_elem = INT_MAX;
        int repeat_times = 0;
        while(j < nums.size()){
            if(nums[j] == cur_elem) ++repeat_times;
            else{
                cur_elem = nums[j];
                repeat_times = 0;
            }
            if(repeat_times > 1) {
                ++j;
                continue;
            }
            else{
                if(i != j)
                    nums[i] = nums[j];
                ++len;
                ++i; ++j;
            }
        }
        return len;
    }
};
