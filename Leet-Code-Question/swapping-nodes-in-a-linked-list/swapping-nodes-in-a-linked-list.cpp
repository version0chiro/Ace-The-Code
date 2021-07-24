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
    ListNode* swapNodes(ListNode* head, int k) {
        unordered_map<int,ListNode*> m;
        int len=1;
        ListNode* curr = head;
        
        while(curr){
            m[len]=curr;
            len++;
            curr=curr->next;
        }
        
        int start = k;
        int end = len-k;
        
        swap(m[start]->val,m[end]->val);
        
        
        return head;
    }
};