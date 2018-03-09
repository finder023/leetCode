//11. Container With Most Water
//先实现一个最简单的版本
//结果，果然超时了
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
