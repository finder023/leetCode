class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> vnum1(num1.size(), 0);
        vector<int> vnum2(num2.size(), 0);
        vector<int> result(num1.size() + num2.size(), 0);
        int n = num1.size();
        for(int i=0; i<n; ++i){
            vnum1[i] = num1[n - i - 1] - '0';
        }
        n = num2.size();
        for(int i=0; i<n; ++i){
            vnum2[i] = num2[n - i -1] - '0';
        }
        
        for(int i=0; i<vnum2.size(); ++i){
            for(int j=0; j<vnum1.size(); ++j){
                result[i+j] += vnum2[i] * vnum1[j];
            }
        }
        int carry;
        for(int i=0; i<result.size() - 1; ++i){
            carry = result[i] / 10;
            result[i] = result[i] % 10;
            result[i+1] += carry;
        }
        
        n = result.size() - 1;
        while(n>=0 && !result[n]) --n;
        string sr(n>0?n+1:1, '0');
        if(n == -1)
            sr[0] = '0';
        for(int i=n; i>=0; --i){
            sr[n-i] = '0'+result[i];
        }   
        return sr;
    }
};

//这段代码的运行时间挺好
