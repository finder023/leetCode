#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> cr;
    unordered_map<char, int> cm;
    unordered_map<char, int> countc;
    vector<int> cpos;
    int numDistinct(string s, string t) {
        cr = vector<int>(s.size(), -1);
        cpos = vector<int>(t.size(), -1);
        fillRecord(s);
        
        //first fit
        // 注意一个问题，就是保证pos的顺序是增大的
        int reIndex;
        // try to fit
        for (int i=0; i<t.size(); ++i) {
            cpos[i] = cm[s[i]];
        }
        
        while ((reIndex = isFitPos(cpos)) != cpos.size()) {
            int nextIndex;
            if ((nextIndex = cr[cpos[reIndex]]) == -1)
                return 0;
            cpos[reIndex] = nextIndex;
            while (++reIndex < cpos.size()) {
                if (cpos[reIndex] > nextIndex)
                    continue;
                if ((nextIndex = cr[cpos[reIndex]]) == -1)
                    return 0;
            }
        }
        
        

        for (int i=0; i<t.size(); ++i) {
            
        }
    }
    
    int isFitPos(vector<int>& pos) {
        int reIndex;
        for (reIndex = 1; reIndex < cpos.size() && cpos[reIndex] > cpos[reIndex-1]; ++reIndex) { }
        return reIndex;
    }

    
    void fillRecord(string& s) {
        unordered_map<char, int> cmap;
        unordered_map<char, int>::iterator it;
        for (int i=0; i<s.size(); ++i) {
            if ((it = cmap.find(s[i])) == cmap.end()) {
                cmap[s[i]] = i;
                cm[s[i]] = i;
                count[s[i]] = 1;
            }
            else {
                cr[cmap[s[i]]] = i;
                cmap[s[i]] = i;
                ++count[s[i]];
            }
        }
    }
};

int main() {
    string s = "babgbag";
    string t = "bag";

    Solution su;
    int r = su.numDistinct(s, t);
    return 0;
}
