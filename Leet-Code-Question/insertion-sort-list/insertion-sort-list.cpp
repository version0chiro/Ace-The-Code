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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode();
        
        ListNode* curr = newHead;
        ListNode* originalCurr = head;
        
        
        while(1){
            ListNode* minNode = NULL;
            int minVal = INT_MAX;    
            ListNode* originalCurr = head;
            while(originalCurr){
                if(minVal>originalCurr->val){
                    minVal = originalCurr->val;
                    minNode = originalCurr;
                }
                originalCurr=originalCurr->next;
            }
            if(minVal==INT_MAX) return newHead->next;
            
            curr->next = new ListNode(minVal);
            curr=curr->next;
            
            cout<<minNode->val<<" ";
            minNode->val=INT_MAX;
        
        }
        
        return newHead->next;
    }
};