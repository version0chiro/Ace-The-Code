/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
public:
    ListNode *detectCycle(ListNode *head) {
     
        map<ListNode*,int> m;
        if(!head){
            return NULL;
        }
        int count=1;
        ListNode* pointer = head;
        while(pointer){
            cout<<pointer->val<<" "<<endl;
            if(m[pointer]==0){
                m[pointer] = count;
            }else{
                return pointer;
            }
            pointer = pointer->next;
            count++;
        }
        
        return NULL;
    }
};