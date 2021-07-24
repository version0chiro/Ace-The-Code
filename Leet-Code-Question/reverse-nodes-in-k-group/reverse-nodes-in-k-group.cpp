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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr =head;
        ListNode* startHead;
        stack<int> valStack;
        int org=k;
        while(curr){
            if(k==org){
                startHead=curr;
            }
            if(k==0){
                k=org;
                while(!valStack.empty()){
                    startHead->val=valStack.top();
                    valStack.pop();
                    startHead=startHead->next;
                }
            }else{
                valStack.push(curr->val);
                curr=curr->next;
                k--;
            }
        }
        
        if(k==0){
            k=org;
            while(!valStack.empty()){
                startHead->val=valStack.top();
                valStack.pop();
                startHead=startHead->next;
            }
        }
        
        return head;
    }
};