/*
寻找最长的回文子字符串，这个原理上其实很简单，有两个思路，一是动态规划，二是如下代码所示，从中间点开始出发，顺两边延伸寻找最长的回文字符串。
*/

class Solution {
public:
	string longestPalindrome(string s) {
		int length = 0, tmplen = 0;
		string result;
		int i, j;
        int left, right;
		for (i = 0; i < 2*s.length()-1; ++i) {
            for (j = 0; ; ++j) {
                if(i % 2 == 0){
                    left = i/2-j;
                    right = i/2+j;
                }
                else{
                    left = i / 2 - j + 1;
                    right = i - left;
                }
                if (left < 0 || right >= s.length())
                    break;
                if (s[left] == s[right]) {
                    tmplen = right - left + 1;
                    if (tmplen > length) {
                        length = tmplen;
                        result = string(s, left, tmplen);
                    }
                }
                else
                    break;		
            }
		}
		return result;
	}
};
