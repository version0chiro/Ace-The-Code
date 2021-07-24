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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1=list1;
        ListNode* link1=list1;
        ListNode* link2=list1;
        int count=0;
        while(count<=b+1){
            if(count==a-1){
                link1=curr1;
            }
            if(count==b+1){
                link2=curr1;
            }
            curr1=curr1->next;
            count++;
        }
        
        
        link1->next=list2;
        
        curr1=list2;
        while(curr1->next){
            curr1=curr1->next;
        }
        
        curr1->next=link2;
        // cout<<curr1->val<<"\n";
        
        
        
        return list1;
    }
};