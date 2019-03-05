#include <iostream>
#include <map>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    void reorderList(ListNode* head) {
        map<int, ListNode*> nodeMap;
        int index = 0;
        ListNode *node = head;
        while (node) {
            nodeMap[index++] = node;
            node = node->next;
        }
        ListNode *tmp;
        node = head;
        for (int i=0; i<index/2; ++i) {
            tmp = node->next;
            node->next = nodeMap[index-i-1];
            node = node->next;
            node->next = tmp;
        }
        node->next = NULL;
    }
};

int main() {
    Solution su;
    ListNode *head = new ListNode(1), *node;
    node = head;
    for (int i=2; i<5; ++i) {
        node->next = new ListNode(i);
        node = node->next;
    }

    su.reorderList(head);

}