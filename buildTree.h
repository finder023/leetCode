#pragma once

#include "base.h"

void createNode(TreeNode* n, int data[], size_t index, size_t len){
    size_t leftIndex = (index+1) * 2 - 1;
    size_t rightIndex = (index+1) * 2;
    if (leftIndex < len){
        if (data[leftIndex] != emptyVal){
            n->left = new TreeNode(data[leftIndex]);
            createNode(n->left, data, leftIndex, len);
        } else {
            n->left = NULL;
        }
    }
    if (rightIndex < len){
        if (data[rightIndex] != emptyVal){
            n->right = new TreeNode(data[rightIndex]);
            createNode(n->right, data, rightIndex, len);
        } else {
            n->right = NULL;
        }
    }
}   

// 层次遍历树的重建
TreeNode* buildTree(int data[], size_t len){
    if (len == 0) 
        return NULL;

    TreeNode *head = new TreeNode(data[0]);
    createNode(head, data, 0, len);
    return head;
}

void printTree(TreeNode *root){
    if (root == NULL)
        return;
}
