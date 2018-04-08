class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length() == 0)
            return s.length() == 0;
        if(s.length() == 0){
            if(p[0] == '*')
                return isMatch(s, string(p, 1, p.length()-1));
            else
                return false;
        }
        if(p[0] == '?')
            return isMatch(string(s, 1, s.length()-1), string(p, 1, p.length()-1));
        else if(p[0] == '*'){
            return (isMatch(s, string(p, 1, p.length()-1)) || isMatch(string(s, 1, s.length()-1), p) || isMatch(string(s, 1,s.length()-1), string(p, 1, p.length()-1)));
        }
        else
            return (p[0]==s[0] && isMatch(string(s, 1,s.length()-1), string(p, 1, p.length()-1)));
    }
    
};

//递归还是一种试探性的算法，所有的情况都试了一遍，如果是true的话匹配到就可以结束，但是如果是false的话需要遍历所有情况，这要耗费很多的时间，以上程序不出所料，超时了。。。。。。
