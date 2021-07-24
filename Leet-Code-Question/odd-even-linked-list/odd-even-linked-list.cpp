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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* curr2=head->next;
        ListNode* temp=NULL;
        while(curr->next){
            temp=curr->next;
            curr->next=curr->next->next;
            curr=temp;
        }
        curr=head;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=curr2;
        // cout<<prev->val<<" ";
        // prev->next=curr2;
        return head;
    }
};