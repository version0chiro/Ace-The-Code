/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* curr = head;
        
        ListNode* newHead = new ListNode();
        ListNode* curr1=newHead;
        ListNode* prev=NULL;
        
        ListNode* newHead2 = new ListNode();
        ListNode* curr2=newHead2;
        ListNode* prev2=NULL;
        
        while(curr){
            
            if(curr->val>=x){
                curr2->val=curr->val;
                curr2->next = new ListNode();
                prev2=curr2;
                curr2=curr2->next;
            }else{
                curr1->val=curr->val;
                curr1->next = new ListNode();
                prev=curr1;
                curr1=curr1->next;
            }
            curr=curr->next;
        }
        
        if(!prev){
            prev2->next=NULL;
            return newHead2;
            
        } 
        if(!prev2){
            prev->next=NULL;
            return newHead;
        } 
        prev->next = newHead2;
        
        prev2->next=NULL;
        
        return newHead;
        
    }
};