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
