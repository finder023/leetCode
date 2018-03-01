/*
好多细节当时都忽略了
几个条件。1，去除开头的空字符.2.开始数字部分时，如果出现非数字字符，停止转换。3.非法返回0。4.当数值超过INT范围时，返回INT_MIN or INT_MAX
*/

class Solution {
public:
	int myAtoi(string str) {
		int start = 0;
		string sr;
		bool isNegativeSet = false;
		bool isPositiveSet = false;
		while (str[start] == ' ' && start < str.length()) {
			++start;
		}
		if (start == str.length())
			return 0;
		for (int i = start; i < str.length(); ++i) {
			if (str[i] == '-'){
                if(!isNegativeSet && !isPositiveSet)
				    isNegativeSet = true;
                else
                    return 0;
            }
            
			else if (str[i] == '+'){
                if(!isNegativeSet && !isPositiveSet)
                    isPositiveSet = true;
                else
                    return 0;
            }
				
			else if (str[i] <= '9' && str[i] >= '0')
				sr.push_back(str[i]);
            else
                break;
		}
		long long result = 0;
		long long x = 1;
		for (int i = sr.length() - 1; i >= 0; --i) {
			result += (sr[i] - '0') * x;
			x *= 10;
            if(result > INT_MAX)
                break;
		}

		if (isNegativeSet)
			result *= -1;
		if (result >= INT_MAX)
            return INT_MAX;
        else if (result <= INT_MIN)
            return INT_MIN;
		return result;
	}
};
