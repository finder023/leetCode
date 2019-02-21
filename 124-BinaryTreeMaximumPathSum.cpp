/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 需要树的自下而上的遍历，用递归吧，先复制一份
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        //TreeNode *stree = treeCopy(root);
        treeSum(root);
        int m = INT_MIN;
        treeTraval(root, m);
        return m;
    }
    
    void treeSum(TreeNode *node) {
        if (!node)
            return;
        int maxPart = INT_MIN;
        if (node->left) {
            treeSum(node->left);
            if (node->left->val > maxPart)
                maxPart = node->left->val;
        }   
            
        if (node->right) {
            treeSum(node->right);
            if (node->right->val > maxPart)
                maxPart = node->right->val;
        }
        if (maxPart > 0)
            node->val += maxPart;
    }
    
    void treeTraval(TreeNode *node, int &maxVal) {
        if (!node)
            return;
        int min = INT_MAX;
        
        if (node->left && node->right) {
            if (node->left->val < min)
                min = node->left->val;
            if (node->right->val < min)
                min = node->right->val;
            if (min > 0)
                node->val += min;
        }
        if (node->val > maxVal)
            maxVal = node->val;
        treeTraval(node->left, maxVal);
        treeTraval(node->right, maxVal);
    }
};