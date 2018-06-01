class Solution {
public:
    void add_sub_set(vector< vector<int> >& result, vector<int>& nums, vector<int>& tmp, int n, int st){
        if(n <= 0) {
            result.push_back(tmp);
            return;
        }
        for(int i=st; i<nums.size(); ++i){
            if (i > st && nums[i] == nums[i-1])
                continue;
            tmp.push_back(nums[i]);
            add_sub_set(result, nums, tmp, n-1, i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > r;
        
        vector<int> tmp;
        for(int i=0; i<nums.size(); ++i){
            tmp.clear();
            add_sub_set(r, nums, tmp, i, 0);
        }
        r.push_back(nums);
        return r;
    }
};
