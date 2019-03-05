#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head, *slow = head, *pre = NULL;
        if (!head)
            return;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (pre)
            pre->next = NULL;
        // reverse slow
        ListNode *cur = slow->next, *next;
        pre = slow;
        pre->next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        //merge
        cur = head;
        while (1) {
            next = cur->next;
            cur->next = pre;
            pre = pre->next;
            cur = cur->next;
            if (next) {
                cur->next = next;
                cur = cur->next;
            } else 
                break;
        }
    }
};

int main() {
    Solution su;
    ListNode *head = new ListNode(1), *node;
    node = head;
    for (int i=2; i<2; ++i) {
        node->next = new ListNode(i);
        node = node->next;
    }
    su.reorderList(head);
}