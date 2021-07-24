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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head){
            return NULL;
        }
        int count =0;
        ListNode* tempL = head;
        while(tempL){
            tempL=tempL->next;
            count++;
        }
        k=k%count;
        while(k--){
            int temp= head->val;
            int prev = head->val;
            ListNode* curr = head->next;
            while(curr){
                temp = curr->val;
                curr->val = prev;
                prev = temp;
                curr=curr->next;
            }
            
            head->val = prev;
        }
        
        return head;
    }
};