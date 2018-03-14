//括号匹配的一段代码，很简单

#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for(int i=0; i<s.length(); ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                sc.push(s[i]);
            else if(s[i] == ')'){
                if(sc.empty() || sc.top() != '(')
                    return false;
                else 
                    sc.pop();
            }
            else if(s[i] == ']'){
                if(sc.empty() || sc.top() != '[')
                    return false;
                else
                    sc.pop();
            }
            else if(s[i] == '}'){
                if(sc.empty() || sc.top()  != '{')
                    return false;
                else
                    sc.pop();
            }
        }
        if(sc.empty())
            return true;
        return false;
    }
};
