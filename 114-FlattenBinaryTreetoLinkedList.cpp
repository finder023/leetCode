/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
思路事这样的，先用先序遍历，然后在生成一个新的树；（最简单的方法，可能不被允许）

*/
class Solution {
public:
    void preOrder(TreeNode* node, vector<TreeNode*>& vn) {
        if (!node)
            return;
        vn.push_back(node);
        preOrder(node->left, vn);
        preOrder(node->right, vn);
    }
    
    void flatten(TreeNode* root) {
        if (!root)
            return;
        vector<TreeNode*> preOrderList;
        preOrder(root, preOrderList);
        
        unsigned len = preOrderList.size();
        for(unsigned i=0; i<len-1; ++i) {
            preOrderList[i]->left = NULL;
            preOrderList[i]->right = preOrderList[i+1];
        }
    }
};