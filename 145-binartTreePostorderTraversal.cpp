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
    vector<int> postorderTraversal(TreeNode* root) {
        deque<int> dres;
        vector<int> res;
        stack<TreeNode*> d;
        if (!root)
            return res;
        TreeNode *node = root;
        while (!d.empty() || node) {
            if (node) {
                d.push(node);
                dres.push_front(node->val);
                node = node->right;
            } 
            else {
                node = d.top();
                d.pop();
                node = node->left;
            }
        }
        res = vector<int>(dres.begin(), dres.end());
        return res;
    }
};