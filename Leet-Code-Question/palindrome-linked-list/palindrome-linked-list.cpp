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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast  = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = reverseList(slow);
        fast = head;
        
        while(slow){
            if(fast->val != slow->val){
                return false;
            }
            slow=slow->next;
            fast = fast->next;
        }
        
        return true;
        
    }
};