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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* curr = head;
        int len=0;
        while(curr){
            st.push(curr);
            curr=curr->next;
            len++;
        }
        
        curr=head;
        
        int count=0;
        while(count<len && curr!=st.top()){
            // cout<<curr->val<<" "<<st.top()->val<<" ";
            ListNode* temp = curr->next;
            curr->next=st.top();
            st.pop();
            curr->next->next=temp;
            curr=temp;
            count=count+2;
        }
        curr->next=NULL;
        // cout<<"\n";
        // cout<<curr->next->next->val<<"\n";
    }
};