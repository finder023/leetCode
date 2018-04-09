class Solution {
public:
	int jump(vector<int>& nums) {
	vector<int> mem(nums.size(), INT_MAX);
        mem[mem.size()-1] =0;
        int templen = 0;
        for(int i=nums.size()-1; i>=0; --i){   
            for(int j = i+1; j<=i+nums[i] && j < nums.size(); ++j){
                templen = 1+mem[j];
                if(mem[i]>=templen && templen > 0)
                    mem[i] = templen;
            }
        }
        return mem[0];
		
	}

};

//动态规划算法都超时了。。。。。。
class Solution {
public:
	int jump(vector<int>& A) {
		int n = A.size();
		if (n<2)return 0;
		int level = 0, currentMax = 0, i = 0, nextMax = 0;

		while (currentMax - i + 1>0) {		//nodes count of current level>0
			level++;
			for (; i <= currentMax; i++) {	//traverse current level , and update the max reach of next level
				nextMax = max(nextMax, A[i] + i);
				if (nextMax >= n - 1)return level;   // if last element is in level+1,  then the min jump=level 
			}
			currentMax = nextMax;
		}
		return 0;
	}

};
//还是先前的那种贪心思路，不过方法上改进了一下
