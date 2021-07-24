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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* newHead = l3;
        int carry=0;
        while(l1 && l2){
            int sum = l1->val + l2->val+carry;
            int ones = sum%10;
            l3->next = new ListNode(ones );
            carry = (sum)/10;
            l3=l3->next;
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            while(l1){
                l3->next = new ListNode((l1->val + carry)%10);
                carry = (l1->val+carry)/10;
                l3=l3->next;
                l1=l1->next;
            }
        }else if(l2){
            while(l2){
                l3->next = new ListNode((l2->val + carry)%10);
                carry = (l2->val+carry)/10;
                l3=l3->next;
                l2=l2->next;
            }            
        }
        if(carry>0){
            l3->next = new ListNode(carry);
        }
        
        return newHead->next;
    }
};