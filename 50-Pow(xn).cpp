//这个题有很多要注意的点，就是当x = +-1时的情况，还有n是最小负整数时的情况，这里都做了偷懒的处理，就是不考虑溢出。。。
//所以这个耿直的方法耗了很多时间

class Solution {
public:
    double myPow(double x, int n) {
        long long ln = n;
        if(x == 0)
            return 0;
        if(ln < 0){
            x = 1.0 / x;
            ln=-ln;
        }
        return subPow(x, ln);
    }
    
    double subPow(double x, long long n){
        if(n == 0) return 1;
        if(n < 2) return x;
        if(n % 2 == 0)
            return subPow(x, n/2) * subPow(x, n/2);
        else
            return subPow(x, n/2+1) * subPow(x, n/2);
    }
};
