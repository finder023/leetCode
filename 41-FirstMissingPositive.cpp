//这个要求感觉是不可完成的，O(n)的复杂度和常数空间
//只允许遍历一遍就找出来
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> flag(nums.size(), 0);
        int i;
        for(i=0; i<nums.size(); ++i){
            if(nums[i] > 0)
                flag[nums[i]] = 1;
        }
        i = 1;
        while(flag[i]) ++i;
        return i;
    }
};

//这个实现空间复杂度不符合要求
