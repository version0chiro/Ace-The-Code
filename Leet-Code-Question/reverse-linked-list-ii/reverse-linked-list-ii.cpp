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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return head;
        if(left==right) return head;
        unordered_map<int,ListNode*> m;
        
        int l=0;
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(curr){
            l++;
            m[l]=curr;
            if(l>=left && l<=right){
                temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }else{
                curr=curr->next;
            }
        }
        
        cout<<m[left]->val<<" "<<m[right]->val;
        m[left]->next=m[right+1];
        if(left-1>0)
            m[left-1]->next=m[right];
        else return m[right];
        
        return head;
        
        
    }
};