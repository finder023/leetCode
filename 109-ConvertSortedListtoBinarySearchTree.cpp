#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return NULL;
        int len = 0;
        
        for(ListNode *node = head; node; node=node->next)
            ++len;
        TreeNode *thead = new TreeNode(0);
        fillNode(thead, head, len / 2, len - len / 2 - 1);
        return thead;
    }
    
    void fillNode(TreeNode *node, ListNode *st, int leftLen, int rightLen) {
        ListNode *n = st;
        for(int i=0; i<leftLen; ++i)
            n = n->next;
        node->val = n->val;
        if (leftLen >= 1) {
            TreeNode *l = new TreeNode(0);
            node->left = l;
            fillNode(l, st, leftLen / 2, leftLen - leftLen / 2 - 1);
        }
        if (rightLen >= 1) {
            TreeNode *r = new TreeNode(0);
            node->right = r;
            fillNode(r, n->next, rightLen / 2, rightLen - rightLen / 2 - 1);
        }
        
    }
};

int main() {
    int a[] = {-10,-3,0,5,9};
    int len = 5;
    ListNode * head = new ListNode(a[0]);
    ListNode *node = head;
    for (int i=1; i<len; ++i) {
        head->next = new ListNode(a[i]);
        head = head->next;
    }

    Solution su;
    TreeNode *root = su.sortedListToBST(node);
    return 0;
}