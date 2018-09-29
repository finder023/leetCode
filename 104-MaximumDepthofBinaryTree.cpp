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
    int maxDepth(TreeNode* root) {
        int mDepth = 0;
        queue<TreeNode*> q;
        int countCur = 0, countNext = 0;
        if (!root)
            return 0;
        q.push(root);
        ++countCur;
        ++mDepth;
        while(!q.empty()) {
            TreeNode *curNode = q.front();
            q.pop();
            if(curNode->left) {
                q.push(curNode->left);
                ++countNext;
            }
            if (curNode->right) {
                q.push(curNode->right);
                ++countNext;
            }
            
            --countCur;
            if (countCur <= 0) {
                countCur = countNext;
                countNext = 0;
                if (countCur)
                    ++mDepth;
            }
        }
        return mDepth;
    }
};