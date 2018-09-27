/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool checkSame(struct TreeNode *p, struct TreeNode *q) {
    if (p == NULL && q == NULL)
        return true;
    if (p != NULL ^ q != NULL)
        return false;
    if (p->val == q->val) 
        return checkSame(p->left, q->left) && checkSame(p->right, q->right);
    else
        return false;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    return checkSame(p, q);
}