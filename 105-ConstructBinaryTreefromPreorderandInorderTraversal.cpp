
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
    int findIndex(vector<int>& data, int val, int i, int j) {
        vector<int>::iterator it;
        it = std::find(data.begin()+i, data.begin()+j, val);
        if (it == data.end())
            return -1;
        else 
            return it - data.begin();
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return NULL;
        TreeNode *head = new TreeNode(0);
        _build(preorder, inorder, head, 0, preorder.size(), 0, inorder.size());
        return head;
    }
    
    void _build(vector<int>& preorder, vector<int>& inorder, TreeNode *node, int prei, int prej, int ini, int inj) {
        if (prej <= prei || inj <= ini)
            return;
        int nodeVal = preorder[prei];
        int valIndex;
        node->val = nodeVal;
        valIndex = findIndex(inorder, nodeVal, ini, inj);
        int leftLen = valIndex - ini;
        if (leftLen > 0) {
            TreeNode *l = new TreeNode(0);
            node->left = l;
            _build(preorder, inorder, l, prei+1, prei+1+leftLen, ini, ini+leftLen);
        }
        int rightLen = inj - valIndex - 1;
        if (rightLen > 0) {
            TreeNode *r = new TreeNode(0);
            node->right = r;
            _build(preorder, inorder, r, prei+1+leftLen, prej, valIndex+1, inj);
        }
        
    }
};