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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr= head;
        ListNode* temp = head;
        if(!head){
            return NULL;
        }
        
        int tempData = curr->val;
        curr=curr->next;
        while(curr){
            if(curr->val==tempData){
                temp->next=curr->next;
                curr=temp->next;
            }else{
                tempData=curr->val;
                temp=temp->next;
                curr=curr->next;
                
            }
        }
        return head;
    }
};