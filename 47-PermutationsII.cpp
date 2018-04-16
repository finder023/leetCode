//和上一个不同之处在于避免重复，实现起来也简单

#include <alogrithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > r;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //必要的排序
        sort(nums.begin(), nums.end());
        vector<bool> tag(nums.size(), false);
        vector<int> result(nums.size(), 0);
        int n = 0;
        permuteint(nums, result, tag, n);
        return r;
    }
    
    void permuteint(vector<int>& nums, vector<int>& result, vector<bool>& tag, int n){
        if (n >= nums.size()){
            r.push_back(result);
            return;
        }
        
        for(int i=0; i<nums.size(); ++i){
            if(!tag[i]){
                result[n] = nums[i];
                tag[i] = true;
                permuteint(nums, result, tag, n+1);
                tag[i] = false;
                //一开始这里用的是if,导致无法避开重复多次的数值
                while(i+1 < nums.size() && nums[i] == nums[i+1])
                    ++i;
            }
        }
    }
};
