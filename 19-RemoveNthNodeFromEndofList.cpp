/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* x = new ListNode(0);
        x->next = head;
        ListNode* node = x;
        ListNode* tag = x;
        int len = 0;
        while(node->next != NULL){
            node = node->next;
            if(++len > n){
                tag = tag->next;
            }  
        }
        tag->next = tag->next->next;
        return x->next;
    }
};
