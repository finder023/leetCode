/*
正则表达的‘*’和'.'的匹配程序

惭愧，这个也是抄别人的程序，还有一个动态规划实现的版本，效率更高，可以在程序的基础上进行修改
一开始相当的一段段匹配，而该算法是对每个字符进行逐一匹配，可以尝试一下不递归的版本，可能更加高效
*/


class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.length() == 0)
            return s.length() == 0;
        bool firstMatch = (s.length() != 0 && (s[0] == p[0] || p[0] == '.'));
        if(p.length() > 1 && p[1] == '*'){
            return (isMatch(s, string(p, 2, p.length()-2)) || (firstMatch && isMatch(string(s, 1, s.length()-1), p)));
        }
        else
            return firstMatch && isMatch(string(s, 1, s.length()-1), string(p, 1, p.length()-1));

	}
};

