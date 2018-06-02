/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//用一个栈来保存节点
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) return head;
        stack<ListNode*> stackbuff;
        ListNode **phead = &head;
        ListNode *st = NULL, *ed = NULL, *node = head;
        int count = 0;
        while(node != NULL){                
            if(++count == m-1)
                st = node;
            if(count >= m && count <= n)
                stackbuff.push(node);
            if(count == n){
                ed = node->next;
                break;
            }
            node = node->next;
        }
        bool once = true;
        while(!stackbuff.empty()){
            if(once && m == 1){
                st = stackbuff.top();
                stackbuff.pop();
                *phead = st;
                once = false;
                continue;
            }
            st->next = stackbuff.top();
            stackbuff.pop();
            st = st->next;
        }
        st->next = ed;
        return *phead;
    }
};


//不用栈的方法
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) return head;
        ListNode *phead = new ListNode(0);
        phead->next = head;
        ListNode *st = NULL, *ed = NULL, *node = phead;
        int count = 0;
        for(int i=1; i<m; ++i){
            node = node->next;
        }
        st = node->next;
        for(int j=0; j<n-m; ++j){
            ed = st->next;
            st->next = ed->next;
            ed->next = node->next;
            node->next = ed;
        }
        
        return phead->next;
    }
};
