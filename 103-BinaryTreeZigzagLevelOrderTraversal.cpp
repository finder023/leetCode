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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> curLevel;
        vector< vector<int> > res;
        vector<int> tmp;
        queue<TreeNode*> q;
        int countCur = 0, countNext = 0;
        bool left = true;
        if (!root)
            return res;
        q.push(root);
        ++countCur;
        while(!q.empty()) {
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
            --countCur;
            curLevel.push_back(curNode->val);
            if (countCur <= 0) {
                if (left) 
                    res.push_back(curLevel);
                else {
                    tmp.clear();
                    for (int i = curLevel.size()-1; i>=0; --i)
                        tmp.push_back(curLevel[i]);
                    res.push_back(tmp);
                }
                tmp.clear();
                curLevel.clear();
                left = !left;
                countCur = countNext;
                countNext = 0;
            }
        }
        return res;
        
    }
};