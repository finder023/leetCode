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
        return checkSame(p->left, q->right) && checkSame(p->right, q->left);
    else
        return false;
}


bool isSymmetric(struct TreeNode* root) {
    if (!root)
        return true;
    return checkSame(root->left, root->right);
}