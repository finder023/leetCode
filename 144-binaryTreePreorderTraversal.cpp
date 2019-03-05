/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal1(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        preOrder(root, res);
        return res;
    }
    
    void preOrder(TreeNode *node, vector<int>& res) {
        if (!node)
            return;
        res.push_back(node->val);
        preOrder(node->left, res);
        preOrder(node->right, res);
    }
    
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode*> s;
        vector<int> res;
        if (!root)
            return res;
        TreeNode *node = root;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                res.push_back(node->val);
                node = node->left;
            }
            else {
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
        return res;
    }
    
};