#include <vector>
#include <string>

using namespace std;

// 也可以做成一个递归的处理，把所有的分割情况都做了，
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        partStr(s, res, path);
        return res;
    }
    
    bool isPalindrome(string s) {
        string::iterator it = s.begin(); 
        string::reverse_iterator rit = s.rbegin();
        while (it != s.end()) {
            if (*it != *rit)
                return false;
            ++it;
            ++rit;
        } 
        return true;
    }
    
    void partStr(string s, vector<vector<string>> &res, vector<string> &path) {
        if (s.length() == 0)
            return;
        if (isPalindrome(s)) {
            path.push_back(s);
            res.push_back(path);
            path.pop_back();
        }
        
        for (int i=1; i<s.length(); ++i) {
            string tmps = s.substr(0, i);
            if (isPalindrome(tmps)) {
                path.push_back(tmps);
                partStr(s.substr(i, s.length() - i), res, path);
                path.pop_back();
            }
        }
    }
};

int main() {
    string input = "aab";
    Solution su;
    auto res = su.partition(input);
}