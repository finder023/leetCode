#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)
            return NULL;
        TreeNode *head = new TreeNode(0);
        fillNode(nums, head, 0, nums.size()-1);
        return head;
    }
    void fillNode(vector<int>& nums, TreeNode *node, int st, int ed) {
        if (st > ed)
            return;
        int mid = (st + ed) / 2;
        node->val = nums[mid];
        if (mid > st) {
            TreeNode *l = new TreeNode(0);
            node->left = l;
            fillNode(nums, l, st, mid-1);
        }
        if (mid < ed) {
            TreeNode *r = new TreeNode(0);
            node->right = r;
            fillNode(nums, r, mid+1, ed);
        }
        
    }
};