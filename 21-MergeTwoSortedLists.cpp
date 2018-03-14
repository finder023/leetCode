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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        
        ListNode* node = new ListNode(0);
        ListNode* tag = node;
        
        while(node1 != NULL && node2 != NULL){
            if(node1->val <= node2->val){
                node->next = node1;
                node1 = node1->next;
            }
            else{
                node->next = node2;
                node2 = node2->next;
            }
            node = node->next;
        }
        if(node1 == NULL)
            node->next = node2;
        else
            node->next = node1;
        return tag->next;
    }
};
