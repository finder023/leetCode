#pragma once

#include "base.h"
#include "lqueue.h"


// 层次遍历树的重建
TreeNode* buildTree(int data[], size_t len){
    if (len == 0) 
        return NULL;

    TreeNode *head = new TreeNode(data[0]);
    TreeNode *node;

    queue<TreeNode*> nodeQueue;
    nodeQueue.push(head);
    for (size_t i=1; i<len && !nodeQueue.empty();){
        node = nodeQueue.front();
        if (data[i] != emptyVal){
            node->left = new TreeNode(data[i]);
            nodeQueue.push(node->left);
        }
        if (data[i+1] != emptyVal){
            node->right = new TreeNode(data[i+1]);
            nodeQueue.push(node->right);
        }
        i+=2;
        nodeQueue.pop();
    }
    return head;
}

void printTree(TreeNode *root){
    if (root == NULL)
        return;
    queue<TreeNode*> nodeQueue;
    TreeNode *node = root;
    nodeQueue.push(node);
    while(!nodeQueue.empty()){
        node = nodeQueue.front();
        nodeQueue.pop();
        printf("%d ", node->val);
        if (node->left != NULL)
            nodeQueue.push(node->left);
        if (node->right != NULL)
            nodeQueue.push(node->right);
    }
    printf("\n");
}

void destroyNode(TreeNode* node){
    if (node == NULL)
        return;
    destroyNode(node->left);
    destroyNode(node->right);
    delete node;
}
