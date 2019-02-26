#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
#include <unordered_set>

using namespace std;

// 这个用递归逐渐试吧
// 判断只有一个字符不同的函数
class Solution {
public:
    int length = INT_MAX;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (vector<string>::iterator it = wordList.begin(); it != wordList.end(); ++it) {
            wordSet.insert(*it);
        }
        
        unordered_set<string>::iterator it;
        if ((it = wordSet.find(beginWord)) != wordSet.end())
            wordSet.erase(it);
        int len = 1;
        for (int i=0; i<beginWord.length(); ++i) {
            matchWord(beginWord, endWord, i, len, wordSet);
        }
        return length == INT_MAX ? 0 : length;
        
    }
    
    void matchWord(string curWord, string endWord, int index, int &len, unordered_set<string> &wordSet) {
        if (index < 0 || index >= endWord.length())
            return;
        if (curWord == endWord) {
            if (len < length)
                length = len;
            return;
        }
        
        if (wordSet.empty())
            return;
        string tmpWord = curWord;
        char c = 'a';
        unordered_set<string>::iterator it;
        for (int i=0; i<26; ++i) {
            tmpWord[index] = c + i;
            if ((it = wordSet.find(tmpWord)) != wordSet.end()) {
                ++len;
                wordSet.erase(it);
                for (int j=0; j<tmpWord.length(); ++j) {
                    if (j == index)
                        continue;
                    matchWord(tmpWord, endWord, j, len, wordSet);
                }
                --len;
                wordSet.insert(*it);
            }
        }
    }
    
};


int main() {
    Solution su;
    string beginWord = "qa", endWord = "sq";
    //string beginWord = "hit", endWord = "cog";
    //vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> wordList = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};;
    

    int re = su.ladderLength(beginWord, endWord, wordList);
    cout << re << endl;
}



