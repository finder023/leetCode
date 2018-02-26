/*
这道题挺简单，没什么可说的
*/

class Solution {
public:
	string convert(string s, int numRows) {
        if(numRows == 1 || s.length() <= 1)
            return s;
		vector<string> data(numRows);
		int z = numRows - 2;
		int j, k, i=0;
		int count = 0;
		bool isEnd = false;
		while (!isEnd) {
			count = 0;
			for (j = 0; j<numRows + z; ++j) {
				if (i >= s.length()) {
					isEnd = true;
					break;
				}

				if (count < numRows) {
					data[count].push_back(s[i]);
				}
				else {
					data[2*numRows-count-2].push_back(s[i]);
				}
				++i;
				++count;
			}
		}
		string result;
		for (int i = 0; i<numRows; ++i) {
			result += data[i];
		}
		return result;
	}
};
