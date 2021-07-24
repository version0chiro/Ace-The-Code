/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return NULL;
        }
        queue<Node*> q;
       
       q.push(root);
       
//       10 20 30 40 60
// 40 20 60 10 30
       
       while(!q.empty()){
           int s = q.size();
           auto prev=q.front();
           for(int i=0;i<s;i++){
               auto temp = q.front();
               q.pop();
               if(temp!=prev){
                   prev->next=temp;
                   prev=temp;
               }
               
            //   cout<<temp->data<<" ";
               if(temp->left){
                   
                q.push(temp->left);
               }
               if(temp->right){
                   q.push(temp->right);
               }
                
                
           }
        //   cout<<"\n";
       }
        
        return root;
    }
};