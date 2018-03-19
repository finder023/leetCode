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
    ListNode* swapPairs(ListNode* head) {
        ListNode* tag = new ListNode(0);
        tag->next = head;
        
        ListNode* curNode1;
        ListNode* curNode2;
        ListNode* nextNode;
        ListNode* node = head;
        ListNode* preNode = tag;
        while(node != NULL){
            
            curNode1 = node;
            curNode2 = node->next;
            if(curNode2 == NULL)
                break;
            
            nextNode = curNode2->next;
            preNode->next = curNode2;
            curNode2->next = curNode1;
            
            preNode = curNode1;
            curNode1->next = nextNode;
            node = nextNode;
            
        }
        
        return tag->next;
    }
};
