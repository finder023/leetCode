/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > res;
        std::queue<TreeNode*> q;
        vector<int> tmp;
        int countCur = 0, countNext = 0;
        if (!root)
            return res;
        q.push(root);
        ++countCur;
        while (!q.empty()) {
            TreeNode *curNode = q.front();
            q.pop();
            if (curNode->left) {
                q.push(curNode->left);
                ++countNext;
            }
            if (curNode->right) {
                q.push(curNode->right);
                ++countNext;
            }
            tmp.push_back(curNode->val);
            --countCur;
            if (countCur <= 0) {
                res.push_back(tmp);
                tmp.clear();
                countCur = countNext;
                countNext = 0;
            }
        }
        return res;
        
    }
};