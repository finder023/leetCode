//贪心思想
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string> r;
        string curline;
        int curlen, curwords, wordslen;
        int spaces;
        string numspace1, numspace;
        int startid;
        for(int i=0; i<words.size(); ){
            startid = i;
            curline.clear();
            curlen = 0, curwords = 0, wordslen = 0;
            while( i<words.size() && curlen + words[i].length() <= maxWidth ){
                curlen += words[i].length();
                wordslen += words[i].length();
                if (curlen < maxWidth)
                    ++curlen;
                ++curwords;
                ++i;
            }
            spaces = maxWidth - wordslen;
            numspace1.clear();
            numspace.clear();
            if(curwords > 1){
                for(int j=0; j<spaces/(curwords-1); ++j)
                    numspace += ' ';
                numspace1 = numspace + ' ';
                for(int j = 0; j<curwords-1; ++j){
                    curline += words[startid + j];
                    if(i != words.size()){
                        if(j < spaces % (curwords-1) )
                            curline += numspace1;
                        else
                            curline += numspace;
                    }
                    else
                        curline += ' ';
                }
            }
            curline += words[startid + curwords - 1];
            while(curline.length() < maxWidth){
                curline += ' ';
            }
            r.push_back(curline);
        }
        return r;
    }
};
