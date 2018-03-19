//用一个最小堆实现，时间复杂度为O(nlog(n))

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class minHeap{
    private:
    vector<ListNode*>& data;
    int heapSize;
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    
    
    public:
    minHeap(vector<ListNode*>& d):data(d), heapSize(data.size()){
        assert(d.size() > 0);
    }
    void heapify(int i){
        int min = i;
        if(left(i) < heapSize && data[left(i)]->val < data[min]->val)
            min = left(i);
        if(right(i) < heapSize && data[right(i)]->val < data[min]->val)
            min = right(i);
        if(min != i){
            ListNode* t = data[i];
            data[i] = data[min];
            data[min] = t;
            heapify(min);
        }
    }
    void buildMinHeap(){
        for(int i = heapSize / 2 - 1; i>=0; --i){
            heapify(i);
        }
    }
    
    ListNode* extractMin(){
        assert(heapSize > 0);
        ListNode* t = data[0];
        ListNode* n = t->next;
        if(n != NULL)
            data[0] = n;
        else
            data[0] = data[--heapSize];
        heapify(0);
        return t;
    }
    
    int size(){
        return heapSize;
    }
    
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> curNode;
        for(int i=0; i<lists.size(); ++i){
            if(lists[i] != NULL)
                curNode.push_back(lists[i]);
        }
        if(curNode.size() == 0)
            return NULL;
        ListNode* tag = new ListNode(0);
        ListNode* node = tag;
        minHeap mheap(curNode);
        mheap.buildMinHeap();
        while(mheap.size() > 0){
            node->next = mheap.extractMin();
            node = node->next;
        }
        
        return tag->next;
    }
};
