/*
 Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:

[
  [7],
  [2, 2, 3]
]

*/


//这段代码用回溯法求解，耗时较长，回头看看他们的代码实现方法
//比较棘手的地方是如何高效或者巧妙的规避重复的答案，这里的实现方式是很原始暴力的，不可取
class Solution {
public:
	vector< vector<int> > result;
	bool isin(vector<int>& data) {
		if (result.size() == 0)
			return false;
		int j = 0;
		for (int i = 0; i < result.size(); ++i) {
			if (data.size() == result[i].size()) {
				j = 0;
				while ( j < data.size() && data[j] == result[i][j]) ++j;
				if (j == data.size())
					return true;
			}
		}
		return false;
	}
	void combination(vector<int>& data, int target, vector<int>& track, unordered_map<int, int>& imap) {
		int rest;
		unordered_map<int, int>::iterator it;
		for (int i = 0; i<data.size(); ++i) {
			rest = target - data[i];
			if (rest < data[0] && rest != 0)
				continue;
			track.push_back(data[i]);
			if (rest == 0) {
				vector<int> temp(track.begin(), track.end());
				sort(temp.begin(), temp.end());
				if (!isin(temp))
					result.push_back(vector<int>(track.begin(), track.end()));
				track.pop_back();
				continue;
			}
			if ((it = imap.find(rest)) != imap.end()) {
				track.push_back(rest);
				vector<int> temp(track.begin(), track.end());
				sort(temp.begin(), temp.end());
				if (!isin(temp))
					result.push_back(vector<int>(track.begin(), track.end()));
				track.pop_back();
			}
			
			combination(data, rest, track, imap);
			track.pop_back();
		}
		//track.pop_back();

	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		unordered_map<int, int> imap;
		for (int i = 0; i<candidates.size(); ++i) {
			imap[candidates[i]] = i;
		}
		sort(candidates.begin(), candidates.end());
		vector<int> track;
		combination(candidates, target, track, imap);
		return result;
	}
};

//下面是一个标准的回溯法算法，不用哈希表就可以实现，设立过多的情况会让程序变得复杂难以掌控，同时，果然有巧妙的避免重复的方法，这样，运行时间变为上面程序的1/3
class Solution {
public:
    
    void backtrack(vector<int>& data, vector< vector<int> >& result, vector<int>& track, int target, int start){
        if(target < 0)
            return;
        else if(target == 0){
            result.push_back(vector<int>(track.begin(), track.end()));
            return;
        }
        else{
            for(int i=start; i<data.size(); ++i){
                track.push_back(data[i]);
                backtrack(data, result, track, target-data[i], i );
                track.pop_back();
            }
        }
        
    }
	
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector< vector<int> > result;
        	vector<int> track;
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, result, track, target, 0);
		return result;
	}
};
