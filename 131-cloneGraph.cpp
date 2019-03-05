/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    map<Node*, Node*> nodeMap;
    Node* cloneGraph(Node* node) {
        if (!node)
            return NULL;
        return clone(node);
    }
    
    Node* clone(Node *node) {
        if (nodeMap.find(node) != nodeMap.end()) 
            return nodeMap[node];
        Node *n = new Node();
        nodeMap[node] = n;
        n->val = node->val;
        vector<Node*>::iterator it;
        for (it = node->neighbors.begin(); it != node->neighbors.end(); ++it) {
            Node *tmp = clone(*it);
            n->neighbors.push_back(tmp);
        }
        return n;
    }
};