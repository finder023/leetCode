//找最长括号匹配的子字符串。
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() < 2)
            return 0;
        stack<char> cstack;
        stack<int> istack;
        int tlen;
        int len = 0;
        int breakpoint;
        
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '(' || cstack.size() == 0 || cstack.top() == ')'){
                cstack.push(s[i]);
                istack.push(i);
            }else {
                cstack.pop();
                istack.pop();
                breakpoint = cstack.size()==0?-1:istack.top();
                tlen = i - breakpoint;
                len = tlen > len?tlen:len;
            }
        }
        return len;
    }
};
