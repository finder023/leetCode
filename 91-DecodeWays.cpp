//这是一个很有意思的题，之前没有察觉到用动态规划，每次都是看前两个字母，如果能组成26以内的数，就要多加一种情况

class Solution {
public:
    int numDecodings(string s) {
        if(s.length() <= 0 || s[0] == '0') return 0;
        int i;
        vector<int> record(s.length()+1, 0);
        record[0] = 1;
        record[1] = s[0] == '0' ? 0:1;
        for(i=1; i<s.length(); ++i){
            if(s[i] <= '9' && s[i] > '0')
                record[i+1] += record[i];
            if( s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '0' && s[i] <= '6'))
                record[i+1] += record[i-1];
        }
        
        return record[record.size()-1];
    }
};
