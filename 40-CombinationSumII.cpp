/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

    All numbers (including target) will be positive integers.
    The solution set must not contain duplicate combinations.

For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:

[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
*/
//在上一道题的基础上做一点小小的改动，跳过重复值即可
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
                backtrack(data, result, track, target-data[i], i+1 );
                track.pop_back();
                while (i + 1 < data.size() && data[i] == data[i + 1])  ++i;
            }
        }
        
    }
	
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	    vector< vector<int> > result;
        vector<int> track;
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, result, track, target, 0);
		return result;
    }
};
