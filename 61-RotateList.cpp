//这里很重要的一个点事将k的值通过k % len 降低到list的长度以内，否则运行时间爆炸

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) 
            return head;
        int i = 0, len = 1;
        ListNode* node = head, *nhead = head;;
        while(node->next != NULL){
            node = node->next;
            ++len;
        }   
        int lk = k % len;
        node->next = head;
        node = head;
        while(1){
            if(i < lk){
                ++i;  
                node = node->next;
                continue;
            }
            if(node->next != head){
                node = node->next;
                nhead = nhead->next;
            }
            else{
                head = nhead->next;
                nhead->next = NULL;
                break;
            }
        }
        return head;
    }
};
