//就是所谓的变位词

#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> sortedString(strs.begin(), strs.end());
        for(int i=0; i<sortedString.size(); ++i){
            sort(sortedString[i].begin(), sortedString[i].end());
        }
        vector< vector<string> > result;
        
        unordered_map<string, int> msi;
        unordered_map<string, int>::iterator it;
        int index = 0;
        for(int i=0; i<sortedString.size(); ++i){
            if((it = msi.find(sortedString[i])) != msi.end())
                result[it->second].push_back(strs[i]);
            else{
                result.push_back(vector<string>(1, strs[i));
                msi.insert(pair<string, int>(sortedString[i], index++));
            }
        }
        return result;
    }
};
