//14. Longest Common Prefix
//很简单的一道题

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        if (strs.size() == 0)
            return string();
        bool continues = true;
        while(1){
            for(int i=0; i<strs.size(); ++i){
                if(index >= strs[i].length() || strs[i][index] != strs[0][index]){
                    continues = false;
                    break;
                }
            }
            if(!continues)
                break;
            ++index;
        }
        if(index == 0)
            return string();
        else
            return string(strs[0], 0, index);
        
        
    }
};
