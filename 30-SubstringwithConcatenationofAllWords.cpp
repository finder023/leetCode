#include <unordered_map>

using namespace std;

//找包含所有words的子字符串，只包含一次，
//words里的字符串是有重复的，不能用哈希表。来写个简单的实现，通过后再改效率
class Solution {
public:

	void clear(vector<int>& data) {
		for (int i = 0; i<data.size(); ++i) {
			data[i] = 0;
		}
	}

	int check(vector<string>& words, vector<int>& tag, string& s) {
		int i = 0, result = -1;
		bool once = false;
		for(i=0; i<words.size(); ++i){
			if (s == words[i])
				if (tag[i])
					once = true;
				else
					break;
		}
		
		if (i == words.size()) {
			if (once)
				return -2;
			return -1;
		}

		return i;

	}

	vector<int> findSubstring(string s, vector<string>& words) {
		//words的标记
		if (words.size() == 0)
			return vector<int>();

		vector<int> result;
		vector<int> tag(words.size(), 0);


		int wordlen = words[0].length();
		string tempstring;
		unordered_map<string, int>::iterator got;
		int start = -1;
		int r = 0;
		for (int i = 0; i<wordlen; ++i) {
			start = -1;
			clear(tag);
			for (int j = i; j<s.length(); j += wordlen) {
				tempstring = string(s, j, wordlen);
				if (tempstring.length() < wordlen) {
					clear(tag);
					continue;
				}
				//got = stringmap.find(tempstring);
				r = check(words, tag, tempstring);
				if (r != -1) {
					if (start == -1)
						start = j;
					if (r != -2) {
						tag[r] = 1;
						int k = 0;
						while (k < tag.size() && tag[k])    ++k;
						if (k == tag.size()) {
							result.push_back(start);
							j = start;
							start = -1;
							clear(tag);
						}

					}
					else {
						clear(tag);
						j = start;
						start = -1;
					}
				}
				else {
					if (start == -1)
						continue;
					else {
						j = start;
						clear(tag);
						start = -1;
					}
				}
			}
		}
		return result;
	}
};
