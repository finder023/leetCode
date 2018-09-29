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
    vector< vector<int> > res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root)
            return res;
        vector<int> p;
        findPath(root, p, 0, sum);
        return res;
    }
    
    void findPath(TreeNode *node, vector<int>& path, int val, int sum) {
        if (!node)
            return;
        val += node->val;
        path.push_back(node->val);
        if (val == sum && !node->left && !node->right)
            res.push_back(path);
        findPath(node->left, path, val, sum);
        findPath(node->right, path, val, sum);
        path.pop_back();
        
    }
};