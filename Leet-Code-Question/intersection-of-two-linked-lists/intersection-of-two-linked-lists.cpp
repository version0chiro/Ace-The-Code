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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,bool> m;
        ListNode* currA = headA;
        while(currA){
            m[currA]=true;
            currA=currA->next;
        }
        ListNode* currB = headB;
        while(currB){
            if(m[currB]){
                return currB;
            }
            currB = currB->next;
        }
        return NULL;
    }
};