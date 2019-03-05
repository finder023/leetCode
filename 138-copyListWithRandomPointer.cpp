#include <map>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    map<Node*, Node*> nmap;
    Node* copyRandomList(Node* head) {
        Node *node, *tmp;
        for (node = head; node != NULL; node = node->next) {
            tmp = new Node();
            tmp->val = node->val;
            nmap[node] = tmp;
        }
        
        for (node = head; node != NULL; node = node->next) {
            nmap[node]->next = nmap[node->next];
            nmap[node]->random = nmap[node->random];
        }
        return nmap[head];
    }
    
};

int main() {
    Solution su;
    Node *head = new Node();
    Node *tail = new Node();
    head->val = 1;
    tail->val = 2;
    head->next = head->random = tail;
    tail->random = tail;
    tail->next = NULL;

    Node *cp = su.copyRandomList(head);
}