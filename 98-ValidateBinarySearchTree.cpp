#include <iostream>
#include "buildTree.h"


/*
判断是否是一个合法的二叉搜索树，用递归的方法
*/
 
class Solution {
private:
    bool isValid(TreeNode* n, TreeNode *p) {
        if (n == NULL) return true;
        TreeNode *l = n->left;
        TreeNode *r = n->right;
        
        if (l != NULL && l->val >= n->val)
            return false;
        if (r != NULL && r->val <= n->val)
            return false;
        //left
        if (p != NULL && l->val >= p->val)
            return false;
        if (p != NULL && l->val <= p->val)
            return false;
        return isValid(l, n) && isValid(r, n);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        return isValid(root, NULL);
    }
};

int main(){
    int data[] = {10, 5, 15, emptyVal, emptyVal, 6, 20};
    TreeNode *root = buildTree(data, 7);

    getchar();
}
