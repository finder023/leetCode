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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = NULL, *node=head, *new_head = NULL;
        ListNode *temp;
        while(node!=NULL){
            temp = node;
            while(temp->next != NULL && temp->next->val == temp->val) temp = temp->next;
            if(temp != node){
                node = temp->next;
                continue;
            }
            if(pre == NULL){
                pre = node;
                node = node->next;
                pre->next = NULL;
                new_head = pre;
            }
            else{
                pre->next = node;
                pre = node;
                node = node->next;
                pre->next = NULL;
            }
        }
        return new_head;
    }
};
