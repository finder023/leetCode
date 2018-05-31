/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//一个比较简单的情况，遍历所有的节点，小于给定值时，将其重新定位到对列前。
//定位操作，每次遍历都是遍历其下一个节点
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode *nil = new ListNode(0);
        nil->next = head;
        ListNode *node = nil;
        ListNode* pos = nil, *tmp;        
        
        while(node != NULL && node->next != NULL){
            if(node->next->val < x){
                if(pos != node){
                    tmp = node->next;
                    node->next = node->next->next;
                    tmp->next = pos->next;
                    pos->next = tmp;
                    pos=pos->next;
                    continue;
                }
                pos = pos->next;
            }
            node = node->next;
        }
        return nil->next;
    }
};
