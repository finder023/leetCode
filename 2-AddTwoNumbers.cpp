/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num = l1->val + l2->val;
        ListNode *result = new ListNode(num % 10);
        int carry = num / 10;
        ListNode *cur = result;
        l1 = l1->next;
        l2 = l2->next;
        
        while(l1 != NULL && l2 != NULL){
            num = carry + l1->val + l2->val;
            carry = num / 10;
            
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1 != NULL){
            num = carry + l1->val;
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            carry = num / 10;
            l1 = l1->next;
        }        
        while(l2 != NULL){
            num = carry + l2->val;
            cur->next = new ListNode(num % 10);
            cur = cur->next;
            carry = num / 10;
            l2 = l2->next;
        }
        if(carry != 0){
            cur->next = new ListNode(carry);
        }
        
        
        return result;
    }
};
