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
        ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0), *cur = dummy;
        dummy->next = head;
        int prefix = 0;
        map<int, ListNode*> m;
        while (cur) {
            prefix += cur->val;
            if (m.count(prefix)) {
                cur =  m[prefix]->next;
                int p = prefix + cur->val;
                while (p != prefix) {
                    m.erase(p);
                    cur = cur->next;
                    p += cur->val;
                }
                m[prefix]->next = cur->next;
            } else {
                m[prefix] = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }};