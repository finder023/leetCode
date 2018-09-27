#pragma once
#include <iostream>


template <class T>
struct ListNode{
    T val;
    ListNode *next;
    ListNode *prev;
    ListNode(T v):val(v), next(NULL), prev(NULL){}
};

template<class T>
class listIterator {
public:
    typedef T value_type;
    typedef ListNode<value_type> node_type;
private:
    node_type *node;
public:
    listIterator(node_type *n):node(n){}
    listIterator():node(NULL){}
    value_type& operator*(){
        return node->val;
    }

    listIterator& operator++(){
        node = node->next;
        return *this;
    }

    bool operator==(listIterator it) {
        return this->node == it.node;
    }

    bool operator!=(listIterator it){
        return this->node != it.node;
    }

    node_type *getNode() const {
        return this->node;
    }

};

template <class T>
class List{
public:
    typedef T value_type;
    typedef ListNode<value_type> node_type;
    typedef listIterator<value_type> iterator;
private:
    ListNode<value_type> *head;
    ListNode<value_type> *tail;
    ListNode<value_type> *node;
    size_t len;
public:
    List():head(NULL), tail(NULL), node(NULL), len(0) {
        tail = new node_type(0);
    }
    ~List(){
        
        ListNode<value_type> *next;
        node = head;
        while(node != NULL){
            next = node->next;
            delete node;
            node = next;
        }
    }

    void push_back(value_type val){
        node = new node_type(val);
        if (!head){
            head = node;
            head->next = tail;
            tail->prev = head;
        } else {
            node->prev = tail->prev;
            tail->prev->next = node;
            node->next = tail;
            tail->prev = node;
        }
        ++len;
    }

    void push_front(value_type val){
        node = new node_type(val);
        if (head == NULL){
            head = node;
            head->next = tail;
            tail->prev = head;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        ++len;
    }

    void pop_back(){
        if (head == NULL)
            return;
        node = tail->prev;
        node_type *npre = node->prev;
        delete node;
        if (!npre){
            head = NULL;
        } else {
            npre->next = tail;
            tail->prev = npre;
        }
        --len;
    }

    void pop_front(){
        if (head == NULL)
            return;
        node = head->next;
        delete head;
        if (node == tail){
            head = NULL;
        } else {
            node->prev = NULL;
            head = node;
        }
        --len;
    }

    // insert one node after n
    void insert(node_type *n, value_type val){
        assert(n != NULL && n != tail);
        node = new node_type(val);
        node->next = n->next;
        n->next->prev = node;
        n->next = node;
        node->prev = n;
        ++len;
    }

    void insert(iterator it, value_type val){
        node_type *n = it.getNode();
        insert(n, val);
    }

    node_type* _erase(node_type *n){
        if (!n || n == tail) return NULL;
        if (n == head){
            node = head->next;
            delete head;
            head = node == tail ? NULL : node;
            return head;
        } else {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            node = n->next;
            delete n;
        }
        return node;
    }

    iterator erase(iterator it){
        return iterator(_erase(it.getNode()));
    }

    bool empty() {
        return len == 0;
    }

    value_type front() const {
        return head->val;
    }
    value_type back() const {
        return tail->prev->val;
    }

    size_t size() const {
        return len;
    }


    iterator begin() {
        return iterator(head);
    }

    iterator end() {
        return iterator(tail);
    }

};
