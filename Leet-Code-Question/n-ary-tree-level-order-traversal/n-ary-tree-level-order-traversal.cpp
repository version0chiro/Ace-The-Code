/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int s = q.size();
            vector<int> tempVec;
            for(int i=0;i<s;i++){
                auto temp = q.front();
                tempVec.push_back(temp->val);
                q.pop();
                for(auto a:temp->children){
                    q.push(a);
                }
            }
            ans.push_back(tempVec);
            
        }
        
        return ans;
    }
};