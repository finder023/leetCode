class Solution {
public:
    vector< vector<int> > result;
    
    void subcombine(vector<int>& tr, vector<bool>& tag, int n, int k, int st){
        if(tr.size() == k){
            result.push_back(tr);
            return;
        }
        for(int i=st; i<=n; ++i){
            if(tag[i-1])  continue;
            tr.push_back(i);
            tag[i-1] = true;
            subcombine(tr, tag, n, k, i+1);
            tr.pop_back();
            tag[i-1] = false;
        }
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        if(n == 0 || k == 0)
            return result;
        vector<bool> tag(n, false);
        vector<int> elem;
        subcombine(elem, tag, n, k, 1);
        return result;
    }
};
