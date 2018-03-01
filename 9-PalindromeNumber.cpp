/*
在不使用额外空间的情况下（不能将整型转换成字符串），判断一个数字是否是回文的

！！！！
这是我抄别人的代码，实现方式实在精妙。将一个整数劈开成了两半，比较这两端是否相等就能判断是否回文，
妙啊~
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    }
};
