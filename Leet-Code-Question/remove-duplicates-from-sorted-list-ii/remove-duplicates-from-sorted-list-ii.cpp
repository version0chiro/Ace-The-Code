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
        map<int,int> m;
        while(head){
            if(m.find(head->val)==m.end()){
                m[head->val]++;
            }else{
                m[head->val]=-1;
            }
            head=head->next;
        }
        
        ListNode* newHead = new ListNode();
        ListNode* curr=newHead;
        for(auto a:m){
            if(a.second==1){
                curr->next = new ListNode(a.first);
                curr=curr->next;
            }
        }
        
        return newHead->next;
    }
};