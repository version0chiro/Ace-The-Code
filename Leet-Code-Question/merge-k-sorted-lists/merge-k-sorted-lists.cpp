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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            ListNode* newHead = &lists[0][0];
            return newHead;
        }
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(auto a:lists){
            while(a){
                pq.push(a->val);
                a=a->next;
            }
        }
        if(pq.size()==0){
            return NULL;
        }
        ListNode* newHead = new ListNode(pq.top());
        pq.pop();
        ListNode* curr=newHead;
        
        while(!pq.empty()){
            curr->next = new ListNode(pq.top());
            curr=curr->next;
            // cout<<pq.top()<<"\n";
            pq.pop();
        }
        
        
        return newHead;
    }
};