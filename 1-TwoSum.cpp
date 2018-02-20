//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.
/*
问题是给定一个数target和一个数组，从数组中找出两个数，使其和为target，用蛮力法实现过程如下，明显的，时间复杂度为 O(n^2)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp(2, 0);
        for(int i=0; i<nums.size()-1; ++i){
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[i] + nums[j] == target){
                    temp[0] = i;
                    temp[1] = j;
                    return temp;
                }
            }
        }
    }
};

/*
改进的一个思路是用hash table，哈希表查找数的时间复杂度接近 O(1)，这样过程如下：
1，对于给定的数组，建立一个哈希表
2，遍历数组元素m，从哈希表中查找target - m，若存在且不为m本身，返回，否则进行下一个元素的查找
这样，时间复杂度为 O(n)
*/
