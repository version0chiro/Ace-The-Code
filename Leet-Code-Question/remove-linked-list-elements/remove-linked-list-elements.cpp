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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
            return NULL;
        }
        ListNode* pointer = head;
        ListNode* prev = new ListNode();
        ListNode* newHead = prev;
        while(pointer){
            if(pointer->val!=val){
                prev->next=new ListNode(pointer->val);
                prev=prev->next;
            }
            pointer=pointer->next;
        }
        return newHead->next;
    }
};