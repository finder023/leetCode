// 排序时间复杂度O(nlogn)
// 对一个数，查找大于或小于该值的数，如果都没有，删除该数，用下一个继续判断，如果有，则顺着该方向继续判断，如果同时有两个

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int length = INT_MIN;
        int curlen = 1;
        
        unordered_set<int> numSet;
        unordered_set<int>::iterator sit;
        vector<int>::iterator vit;
        for (vit = nums.begin(); vit != nums.end(); ++vit) {
            numSet.insert(*vit);
        }
        
        while (!numSet.empty()) {
            // more
            sit = numSet.begin();
            int val = *sit;
            numSet.erase(sit);
            int diff = 1;
            curlen = 1;
            while ((sit = numSet.find(val + diff)) != numSet.end()) {
                ++curlen;
                ++diff;
                numSet.erase(sit);
            }
            
            diff = -1;
            while ((sit = numSet.find(val + diff)) != numSet.end()) {
                ++curlen;
                --diff;
                numSet.erase(sit);
            }
            
            if (curlen > length)
                length = curlen;
        }
        
        return length;
        
    }
};