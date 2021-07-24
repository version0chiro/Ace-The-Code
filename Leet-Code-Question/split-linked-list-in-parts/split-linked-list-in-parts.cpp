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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        
        ListNode* curr = head;
        while(curr){
            curr=curr->next;
            length++;
        }
        vector<ListNode*> ans(k);
        if(length==0) return ans;
        int tempCount = 1;
        int setLength = length/k;
        int extra = length%k;
        if(length<k) extra=0;
        bool first=true;
        
        
        
        curr = head;
        int index=0;
        int count=0;
        while(curr){
            int exC = 0;
            if(count<extra){
                exC = 1;
            }else{
                exC=0;
            }
            tempCount = 1;
    
            int tempSet;
        
            tempSet=setLength+exC;
            
            while(curr && tempCount<tempSet){
                curr=curr->next;
                tempCount++;
            }
            
            if(!curr || !curr->next) break;
            ans[index]=head;
            index++;
            auto temp = curr->next;
            curr->next = NULL;
            head=temp;
            curr = head;
            count++;
   
        }
        
        ans[index]=(head);
        return ans;
    }
};