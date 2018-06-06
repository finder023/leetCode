//二叉树中序遍历，递归方法

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void visit(TreeNode* node, vector<int>& r){
        if(node == NULL)
            return;
        visit(node->left, r);
        r.push_back(node->val);
        visit(node->right, r);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> r;
        visit(root, r);
        return r;
    }
};

//非递归方法、
class Solution 
{
public:
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> result;
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                result.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode* p = cur->left;
                while (p->right != cur && p->right != nullptr)
                {
                    p = p->right;
                }
                
                if (!p->right)
                {
                    p->right = cur;
                    cur = cur->left;
                }
                else
                {
                    p->right = nullptr;
                    result.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return result;
    }
};
