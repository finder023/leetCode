#include <algorithms>

using namespace std;


//第一个版本，复杂度为O(n^2logn)
class Solution {
public:
    //二分搜索
    int search(vector<int>& nums, int t,  int i, int j){
        int k;
        while(i <= j){
            k = (i+j)/2;
            if(nums[k] == t)
                return k;
            if(nums[k] < t){
                i = k+1;
            }
            else{
                j = k-1;
            }
        }
        return -1;
    }
    bool check(vector< vector<int> >& result, int i, int j, int k){
        for(int ii=0; ii<result.size(); ++ii){
            if(result[ii][0] == i && result[ii][1] == j && result[ii][2] == k)
                return false;
        }
        return true;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > result;
        if(nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        int tempk = 0, index;
        for(int i=0; i<nums.size()-2; ++i){
            for(int j=i+1;j<nums.size()-1; ++j){
                
                tempk = nums[i] + nums[j];
                index = search(nums, -tempk, j+1, nums.size()-1);
                if(index != -1){
                    if(result.size() == 0 || check(result, nums[i], nums[j], nums[index])){
                        result.push_back(vector<int>());
                        result[result.size()-1].push_back(nums[i]);
                        result[result.size()-1].push_back(nums[j]);
                        result[result.size()-1].push_back(nums[index]);
                        
                    }
                }
            }
        }
        return result;
    }
};
