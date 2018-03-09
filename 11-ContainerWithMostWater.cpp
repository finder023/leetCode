//11. Container With Most Water
//先实现一个最简单的版本
//结果，果然超时了

/*
从蛮力法优化而来，尽可能的减少计算的次数，淘汰掉不必要的计算。这个是从两边紧逼。时间复杂度为O(N)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
        for(int i=0; i<height.size(); ++i){
            for(int j=height.size()-1; j>i; --j){
                if(min(height[i], height[j]) < temph)
                    continue;
                temph = min(height[i], height[j]);
                temp = (j-i)*temph;
                if(temp > areaMax)
                    areaMax = temp;
            }
        }
        */
        int areaMax = 0;
        int temp = 0;
        int temph = min(height[0], height[height.size()-1]);
        int i=0, j=height.size()-1;
        while(j > i){
            temph = min(height[i], height[j]);
            areaMax = max(areaMax, (j-i)*temph);
            while(height[i]<=temph && i<j) ++i;
            while(height[j]<=temph && i<j) --j;
        }
        return areaMax;
    }
};
