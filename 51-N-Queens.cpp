class Solution {
public:
    
    vector<bool> coltag;
    vector<char> cache;
    vector< vector<string> > result;
    
    bool isvalid(int i, int j, int n){
        if(coltag[j])
            return false;
        int a=i, b=j;
        while(a >=0 && b>=0){
            if(cache[a*n+b] == '.'){
                --a;--b;
            }
            else
                return false;
        }
        a=i; b=j;
        while(a>=0 && b <n){
            if(cache[a*n+b] == '.'){
                --a; ++b;
            }
            else 
                return false;
        }
        return true;
    }
    
    void setQ(int i, int j, int n){
        cache[i*n+j] = 'Q';
        coltag[j] = true;
    }
    void unsetQ(int i, int j, int n){
        cache[i*n+j] = '.';
        coltag[j] = false;
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        coltag = vector<bool>(n, false);
        cache = vector<char>(n*n, '.');
        setrow(0, n);
        return result;
    }
    
    void setrow(int i, int n){
        if(i < 0 || i > n)
            return;
        if(i == n){
            vector<string> temp;
            for(int k=0; k<n; ++k){
                string temps;
                for(int kk=0; kk<n;++kk){
                    temps+=cache[k*n+kk];
                }
                temp.push_back(temps);
            }
            result.push_back(temp);
        }
            
        for(int j=0; j<n; ++j){
            if(isvalid(i, j, n)){
                setQ(i, j, n);
                setrow(i+1, n);
                unsetQ(i, j, n);
            }
            
        }
    }
};
