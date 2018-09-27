#include <iostream>
#include "buildTree.h"


/*
判断是否是一个合法的二叉搜索树，用递归的方法
*/
bool leftCmp(TreeNode *node, TreeNode *left){
    return left->val < node->val;
}

bool rightCmp(TreeNode *node, TreeNode *right){
    return right->val > node->val;
}

class Solution {
private:
    bool isValid(TreeNode* node, bool isLeft, bool (*cmp)(TreeNode*, TreeNode*)){
        if (node == NULL)
            return true;
        TreeNode *son = isLeft ? node->left : node->right;
        if (son == NULL)
            return true;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(son);
        while (!nodeQueue.empty()){
            son = nodeQueue.front();
            nodeQueue.pop();
            if (!cmp(node, son))
                return false;
            if (son->left != NULL)
                nodeQueue.push(son->left);
            if (son->right != NULL)
                nodeQueue.push(son->right);
        }
        bool res = true;
        res = res && isValid(node->left, true, leftCmp);
        res = res && isValid(node->left, false, rightCmp);
        res = res && isValid(node->right, true, leftCmp);
        res = res && isValid(node->right, false, rightCmp);
        return  res ;
    }
    

    
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        return isValid(root, true, leftCmp) && isValid(root, false, rightCmp);
    }
};

int main(){
    //int data[] = {10, 5, 15, emptyVal, emptyVal, 6, 20};
    //int data[] = {3,emptyVal,30,10,emptyVal,emptyVal,15,emptyVal,45};
    int data[] = {3,1,5,0,2,4,6,emptyVal,emptyVal,emptyVal,3};
    TreeNode *root = buildTree(data, 11);
    printTree(root);
    
    Solution su;
    printf(su.isValidBST(root) ? "true\n" : "false\n");
    
    destroyNode(root);

}
