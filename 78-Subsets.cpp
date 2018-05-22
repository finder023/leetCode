class Solution {
public:
    vector< vector<int> > result;
    
    void subcombine(vector<int>& nums, vector<int>& tr, vector<bool>& tag, int n, int k, int st){
        if(tr.size() == k){
            result.push_back(tr);
            return;
        }
        for(int i=st; i<=n; ++i){
            if(tag[i-1])  continue;
            tr.push_back(nums[i-1]);
            tag[i-1] = true;
            subcombine(nums, tr, tag, n, k, i+1);
            tr.pop_back();
            tag[i-1] = false;
        }
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int k;
        vector<bool> tag(nums.size(), false);
        for(k=0; k<=n;++k){
            vector<int> elem;
            subcombine(nums, elem, tag, n, k, 1);
        }
        return result;
    }
};
