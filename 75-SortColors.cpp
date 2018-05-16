class Solution {
public:
    void exchange(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)   return;
        int i=-1, j=-1, p=0;
        while(p < n){
            if(nums[p] == 2){
                if(j == -1)  
                    j = p;
                ++p;
                continue;
            }
            if(nums[p] == 1){
                if(j != -1){
                    exchange(nums, p, j++);
                    if(i == -1)
                        i = j-1;
                }
                if(i == -1)
                    i = p;
                ++p;
                continue;
            }
            if(i==-1 && j == -1)
                ++p;
            else
                exchange(nums, p, i==-1?j++:i++);
            
        }
    }
};
