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

//所以，试试动态规划的方法吧

bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p=='?')||(*p==*s)){s++;p++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p=='*'){star=p++; ss=s;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;  
    }
