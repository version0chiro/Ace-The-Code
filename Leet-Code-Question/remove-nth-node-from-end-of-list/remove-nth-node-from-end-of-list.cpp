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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow = head;
        int n_temp=n;
        while(n_temp){
            fast=fast->next;
            n_temp--;
        }
        if(!fast){
            if(head->next){
                head=head->next;
            }else{
                return NULL;
            }
        }
        ListNode* prev = slow;
        while(slow && fast)
        {   prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=slow->next;
        
        return head;
    }
};