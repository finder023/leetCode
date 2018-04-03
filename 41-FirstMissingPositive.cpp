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

//满足要求的思路就是交换，直接将遍历到的数交换到合适的位置即可
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int i;
		for (i = 0; i<nums.size(); ) {
            //这个判断的条件很重要，缺一不可
			if (nums[i] > 0 && nums[i] < nums.size() && nums[i]-1 != i && nums[nums[i] - 1] != nums[i]) {
				int temp = nums[nums[i]-1];
				nums[nums[i]-1] = nums[i];
				nums[i] = temp;
			}
			else
				++i;
		}
		i = 0;
		while ( i < nums.size() && nums[i]-1 == i) ++i;
		return i+1;
	}
};
