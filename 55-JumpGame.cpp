//用的是动态规划算法，结果时间爆炸

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> reach(nums.size(), false);
        for(int i=nums.size()-1; i>=0; --i){
            for(int j=nums[i]; j>=0; --j){
                if(i + j >=nums.size()-1 || reach[i+j]){
                    reach[i] = true;
                    break;
                }
                    
            }
        }
        return reach[0];
    }
};
