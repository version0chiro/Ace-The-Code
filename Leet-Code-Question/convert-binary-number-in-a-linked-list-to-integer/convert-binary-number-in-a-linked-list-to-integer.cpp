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
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* temp = NULL;
        ListNode* prev = NULL;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    int getDecimalValue(ListNode* head) {
        head=reverseList(head);
        int n = 0;
        int ans = 0;
        while(head){
            
            ans = ans+(head->val)*pow(2,n);
            n++;
            
            head = head->next;
        }
        return ans;
    }
};