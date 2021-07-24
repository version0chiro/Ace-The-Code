/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* newHead = new Node();
    Node* newHeadStart= newHead;
    void solve(Node* head,Node* prev){
        if(!head) return;
        newHead->val=head->val;
        
        newHead->next= new Node();
        newHead=newHead->next;
        if(head->child) solve(head->child,prev);
        
        solve(head->next,prev);
    }
    Node* flatten(Node* head) {
        if(!head) return NULL;
        solve(head,NULL);
        
        // cout<<newHead->prev->val;
        newHead=newHeadStart;
        Node* prev=NULL;
        while(newHead->next){
            // if(prev) cout<<prev->val<<" ";
            // cout<<newHead->val<<" ";
            newHead->prev=prev;
            prev=newHead;
            newHead=newHead->next;
        }
        prev->next=NULL;
        // cout<<"\n";
        // cout<<newHead->val<<" ";
        return newHeadStart;
    }
};