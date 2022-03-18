/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* solve(Node* node, map<Node*, Node*>& seen) {
        if (seen.find(node) != seen.end()) {
            return seen[node];
        }
        Node* answ = new Node();
        seen[node] = answ;
        answ->val = node->val;
        vector<Node*> neighbours;   
        for (auto nbr : node->neighbors) {
            neighbours.push_back(solve(nbr, seen));
        }
        answ->neighbors = neighbours;
        return answ;
    }

    Node* cloneGraph(Node* node) {
        if (node == 0) {
            return 0;
        }
        
        map<Node*, Node*> seen;
        return solve(node, seen);
    }
};