/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 深度优先遍历，用string 记录路径，
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        string pathRecord = "";
        int res = 0;
        
        visitTree(root, pathRecord, res);
        return res;
        
    }
    
    void visitTree(TreeNode *node, string &record, int &res) {
        if (!node)
            return;
        record.push_back('0' + node->val);
        if (!node->left && !node->right) {
            res += stoi(record);
        }
        
        if (node->left) {
            visitTree(node->left, record, res);
        }
        if (node->right) {
            visitTree(node->right, record, res);
        }
        record.pop_back();
    }
    
};