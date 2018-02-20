/*
寻找两个有序数组的中位数，要求时间复杂的是O(log(m+n)),
从最基础的蛮力法开始，思路是类似于归并排序，两个有序数组合并成一个大数组，这个过程很简单，但是复杂度是O(m+n)，不满足题目要求。
log(m+n)复杂度，相比和二分搜索有类似的思路，先实现一种方法，再进行调优。
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp(nums1.size()+nums2.size(), 0);
        int n1=0, n2=0;
        double mid;
        for(int i=0; i<temp.size(); ++i){
            if(n1 < nums1.size() && n2 < nums2.size()){
                if(nums1[n1] < nums2[n2])
                    temp[i] = nums1[n1++];
                else
                    temp[i] = nums2[n2++];
            }
            else if(n1 == nums1.size())
                temp[i] = nums2[n2++];
            else
                temp[i] = nums1[n1++];
            
            
            if(i == temp.size() / 2){
                if(temp.size() % 2 == 0){
                    mid = (double)(temp[i] + temp[i-1]) / 2;
                }
                else
                    mid = temp[i];
                break;
            }
        }
        return mid;
    }
};

/*
这段代码虽然accepted，但是运行速度缓慢，beats 6% of cpp submissions,改进并不简单啊
*/
