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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        ListNode* prev=NULL;
        ListNode* curr= head;
        int temp = head->val;
        int count = 0;
        while(curr){
            if(count==0){
                temp = curr->val;
                count = 1;
            } else{
                prev->val = curr->val;
                curr->val = temp;
                count=0;
            }
            prev = curr;
            curr=curr->next;

        }
        return head;
    }
};