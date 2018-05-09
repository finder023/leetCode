//初步想法是递归


class Solution {
public:
    int factorial(int n){
        int r = 1;
        for(int i=n; i>0; --i)
            r*=i;
        return r;
    }
    
    void fillfirst(string& seq, vector<bool>& used, int n, int k){
        if (n <= 0) return;
        int d = factorial(n-1);
        int fn = k/d;
        if(fn < 0 ) fn = 0;
        int index = 0, i=0;
        //这里如果用最小堆的话效率更高，降低时间复杂度
        while(index <= fn){
            if(used[i++]) continue;
            ++index;
        }
        seq+=('0'+ i);
        used[i-1] = true;
        fillfirst(seq, used, n-1, k % d);
        
    }
    
    string getPermutation(int n, int k) {
        string seq;
        vector<bool> used(n, false);
        fillfirst(seq, used, n, k-1);
        return seq;
    }
    
};
