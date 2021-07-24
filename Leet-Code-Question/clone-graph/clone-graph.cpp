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
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        unordered_map<int,Node*> m;
        m[node->val] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            // cout<<temp->val<<"\n";
            for(auto& a:temp->neighbors){
                if(m.find(a->val)==m.end()){
                    m[a->val]=new Node(a->val);
                    q.push(a);
                }
                m[temp->val]->neighbors.push_back(m[a->val]);
            }
            
            
        }
        
        return m[1];
    }
};