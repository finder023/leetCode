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

/*
这种高难度问题还是交给博客大神了，已跪。
好了这就来分析问题，首先需要明确中位数的作用：将一个数组分为相等的两组数，其中后一组数每一个数都大于前一组数。
题目中给了两个数组A，B，首先随机选取两个数组的分割位置i,j，将其分为四份：
A_left:A[0, 1, ..., i-1]; A_right:A[i, i+1, ..., m];
B_left:B[0,1,..., j-1]; B_right:B[j, j+1, ..., n];
将他们合并成两个数组：
Left:{A_left, B_left}; Right[A_right, B_right];
我们要找的中位数是将Left和Right分开，必须满足两个条件：
(1) Left.length == Right.length
(2) Left.max < Right.min
将这两个条件体现到参数上，就是：
i+j = m-i+n-j; ==> j=(m+n)/2-i; 其中: i=0~m; n>=m
**OR i+j = m-i+n-j+1; ==> j=(m+n+1)/2-i; 其中：i=0~m; n>=m;
**我们喜欢采用后一种方式，这样：j=(m+n+1)/2-i >= (2m+1)/2-m > 0
A[i-1]<=B[j] && B[j-1]<=A[i];

问题就变成了如何选取i的问题，只要选取的i满足条件2，则完成了数组的划分，也就找到了中位数。
关于i的选取，采用二分查找法，可以在O(log(m))时间内找到。
步骤如下：
初始i查找范围为0~m，选取i=m/2
当A[i-1]>B[j]时，说明i过大，需要减小i，重新设定二分查找的范围为0~m/2-1
当A[i]<B[j-1]时，i过小，查找范围为m/2+1~m

这样，程序的时间复杂度为O(log(min(m, n)))!
*/

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int>& A = nums1.size() <= nums2.size() ? nums1 : nums2;
		vector<int>& B = nums1.size()>nums2.size() ? nums1 : nums2;

		int m = A.size();
		int n = B.size();
		int i, j;
		int imin = 0, imax = m;
		double mid;
		if (m == 0) {
			if (n % 2 == 0)
				mid = (double)(B[n / 2] + B[n / 2 - 1]) / 2;
			else
				mid = B[n / 2];
			return mid;
		}
        //主循环
		while (imin <= imax) {
			i = (imax + imin) / 2;
			j = (m + n + 1) / 2 - i;
            //i=0时的边界情况处理
			if (i == 0) {
				if (B[j - 1] <= A[i]) {
					if ((m + n) % 2 == 0) {
						if (j == n)
							mid = (double)(A[i] + B[j - 1]) / 2;
						else
							mid = (double)((B[j]<=A[i]?B[j]:A[i]) + B[j-1]) / 2;
					}
					else
						mid = A[i] <= B[j - 1] ? A[i] : B[j - 1];
					break;
				}
				else {
					imin = i + 1;
					continue;
				}
			}
            //i=m时的边界情况处理
			if (i == m && A[i - 1] <= B[j]) {
				if ((m + n) % 2 == 0) {
					if (j == 0)
						mid = (double)(A[i - 1] + B[j]) / 2;
					else
						mid = (double)((B[j - 1] >= A[i - 1] ? B[j - 1] : A[i - 1]) + B[j]) / 2;
				}
				else {
					mid = B[j - 1] >= A[i-1] ? B[j - 1] : A[i-1];
				}
				break;
			}
			if (A[i - 1] <= B[j] && B[j - 1] <= A[i]) {
				if ((m + n) % 2 == 0) {
					mid = (double)((A[i - 1] >= B[j - 1] ? A[i - 1] : B[j - 1]) + (A[i] <= B[j] ? A[i] : B[j])) / 2;
				}
				else
					mid = A[i - 1] >= B[j - 1] ? A[i - 1] : B[j - 1];
				break;
			}

			if (A[i - 1]>B[j]) {
				imax = i - 1;
			}
			else if (A[i]<B[j - 1]) {
				imin = i + 1;
			}

		}

		return mid;

	}
};
