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

/*
可以针对上述方法进行改进，就是采用所谓的滑动窗口机制，避免了子字符串的重复计算，关键思想是在某个滑动窗口内，没有重复的字符。
这样一直滑动到字符串结束，取最长子序列即可，关键点：
    当遇到重复字符时，窗口始端直接跳转到该字符的后一个字符中，同时调节窗口大小。
##优化后运行时间从50ms降到35ms
*/

#include <unordered_map>

using namespace std;

class Solution {
public:
	int length = 0;

	unordered_map<char, int> hmap;
	unordered_map<char, int>::iterator it;

	int lengthOfLongestSubstring(string s) {

		int tlen = 0;
		for (int i = 0, j = 0; j<s.length();) {
			it = hmap.find(s[j]);
			if (it != hmap.end()) {
                //删除不在窗口中的字符
				for (int k = i; k < it->second; ++k) {
					hmap.erase(s[k]);
				}
                //窗口始端跳转
				i = it->second + 1;
        hmap[s[j]] = j;     //对重复字符的序列号更新，很重要！
				tlen = ++j - i;     //重新计算窗口大小
				continue;
			}
			hmap[s[j]] = j++;
			++tlen;
			if (tlen > length)
				length = tlen;
		}
		return length;
	}
};
