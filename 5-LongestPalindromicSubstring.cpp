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
