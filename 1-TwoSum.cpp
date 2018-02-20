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

#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>  hmap;
        vector<int> result(2, 0);
        for(int i=0; i<nums.size(); ++i){
            hmap[nums[i]] = i;
            //还有另一种插入方式,但运行上并没有变快
            //hmap.insert({nums[i], i});
        }

        unordered_map<int, int>::iterator it;
        int r;
        for(int i = 0; i<nums.size(); ++i){
            r = target - nums[i];
            it = hmap.find(r);
            if(it != hmap.end() && it->second != i){
                result[0] = i;
                result[1] = it->second;
                break;
            }
        }
        return result;
    }
};

/*
哈希表版本的结果好了很多，运行时间从159ms降低到9ms!!
顺便也学习了stl哈希表的使用，以前没用过
*/

#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>  hmap;
        vector<int> result(2, 0);
        unordered_map<int, int>::iterator it;
        int r;
        for(int i=0; i<nums.size(); ++i){
            r = target - nums[i];
            it = hmap.find(r);
            if(it != hmap.end()){
                result[0] = i;
                result[1] = it->second;
                break;
            }

            hmap[nums[i]] = i;

        }
        return result;
    }
};

/*
同样的思路，只是做了一点简化，能节省插入一部分哈希节点的时间 
*/
