//交叉，s3的段总能被s1或者s2所匹配，不能则返回false
//用以前正则表达的思路去做能够实现，但是速度很慢
class Solution {
public:
    bool match(string& s1, string& s2, string& s3, int p1, int p2, int p3){
        if(p3 >= s3.length())
            return true;
        int m1 = p3, m2 = p3;
        int pp1 = p1, pp2 = p2;
        
        bool ismatch = false;
        if(p1 < s1.length() && s3[p3] == s1[p1])
            ismatch = (ismatch || match(s1, s2, s3, p1+1, p2, p3+1));
        if(p2 < s2.length() && s3[p3] == s2[p2])
            ismatch = (ismatch || match(s1, s2,s3, p1, p2+1, p3+1));
        return ismatch;
        
        /*while(pp1 < s1.length() && s3[m1] == s1[pp1]){
            ++m1;
            ++pp1;
        }
        while(pp2 < s2.length() && s3[m2] == s2[pp2]){
            ++m2;
            ++pp2;
        }
        if(m1 == p3 && m2 == p3)
            return false;
        if(m1 != p3 && m2 == p3)
            return match(s1, s2, s3, pp1, p2, m1);
        if(m1 == p3 && m2 != p3)
            return match(s1, s2, s3, p1, pp2, m2);
        if(m1 != p3 && m2 != p3)
            return match(s1, s2, s3, pp1, p2, m1) || match(s1, s2, s3, p1, pp2, m2);*/
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length() + s2.length())
            return false;
        return match(s1, s2, s3, 0, 0, 0);
    }
};
