//递归

class Solution {
public:
    vector< vector<int> > r;
    vector<vector<int>> permute(vector<int>& nums) {
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
            }
        }
    }
};
