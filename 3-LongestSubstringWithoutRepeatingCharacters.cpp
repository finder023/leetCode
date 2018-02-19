/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/

//这是用蛮力法实现的方法，时间复杂度为O(n^2),效果不好
//整个ASCII码有7位，起始字符是NULL，即为0.

class Solution {
public:
    int length = 0;
    
    int index(char s){
        return s - NULL;
    }
    
    
    int lengthOfLongestSubstring(string s) {
        bool tag[128] = {0};
        int tlen = 0;
        for(int i=0; i<s.length(); ++i){
            tlen = 0;
            for(int k = 0; k < 128; ++k){
                tag[k] = 0;
            }
            for(int j = i; j < s.length(); ++j){
                if(!tag[index(s[j])]){
                    tag[index(s[j])] = 1;
                    ++tlen;
                }
                else{ 
                    if(tlen > length){
                        length = tlen;
                    }
                    break;
                }
            }
            if(tlen > length){
                length = tlen;
            }
        }
        
        return length;
    }
};
