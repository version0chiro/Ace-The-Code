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
    pair<ListNode*,ListNode*> FrontAndBackSplit(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        // ListNode* a;
        // ListNode* b;
        while(fast && fast->next){
            fast=fast->next->next;
            slow = slow->next;
        }
        
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next=NULL;
        return make_pair(a,b);
    }
    
    ListNode* mergeList(ListNode* a,ListNode* b){
        ListNode* result = NULL;
        if(a==NULL) return b;
        else if(b== NULL) return a;
        
        if(a->val<=b->val){
            result = a;
            result->next = mergeList(a->next,b);
        }else{
            result = b;
            result->next = mergeList(b->next,a);
        }
        
        return result;
    }
    
    ListNode* sortList(ListNode* head) {
        ListNode* a;
        ListNode* b;
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        auto p=FrontAndBackSplit(head);
        a=p.first;
        b = p.second;
        
        a=sortList(a);
        b=sortList(b);
        
        
        return mergeList(a,b);
    }
};