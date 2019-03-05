class Solution {
public:
    unordered_set<string> wordSet;
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<string>::iterator it;
        for (it = wordDict.begin(); it != wordDict.end(); ++it)
            wordSet.insert(*it);
        vector<bool> record(s.length() + 1, false);
        record[0] = true;
        bool isMatch = false;
        for (int i=1; i<=s.length(); ++i) {
            isMatch = false;
            for (int j=0; j<i; ++j) {
                if (record[j] && wordSet.find(s.substr(j, i-j)) != wordSet.end()) {
                    record[i] = true;
                    break;
                }
            }
        }
        return record[s.length()];
    }
   
};