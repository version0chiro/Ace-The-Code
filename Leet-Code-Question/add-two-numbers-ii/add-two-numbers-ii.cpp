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
    pair<ListNode*,int> reverse(ListNode* l1){
        int length=0;
        ListNode* temp=NULL;
        ListNode* curr = l1;
        ListNode* prev=NULL;
        while(curr){
            temp = curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            length++;
        }
        
        return {prev,length};
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto temp = reverse(l1);
        auto temp2 = reverse(l2);
        
        ListNode* revL1 = temp.first;
        ListNode* revL2 = temp2.first;
        
        int length1 = temp.second;
        int length2 = temp2.second;
        
        int largerLen,shorterLen;
        
        ListNode* longer;
        ListNode* shorter;
        if(length1>length2){
            largerLen = length1;
            shorterLen = length2;
            longer = revL1;
            shorter = revL2;
        }else{
            largerLen = length2;
            shorterLen = length1;
            longer = revL2;
            shorter = revL1;
        }
        
        int carry =0;
        
        ListNode* newHead = longer;
        
        ListNode* prev=NULL;
        
        while(longer && shorter){
            int sum = ( carry + longer->val + shorter->val)%10 ; 
            carry = (carry + longer->val + shorter->val)/10;
            longer->val = sum;
            // cout<<longer->val<<" "<<carry<<"\n";
            prev = longer;
            longer=longer->next;
            shorter=shorter->next;
        }
        
        while(longer){
            if(carry>0){
                int sum=(longer->val+carry)%10;
                carry = (longer->val+carry)/10;
                longer->val = sum;
            }else{
                break;
            }
            prev = longer;
            longer=longer->next;
        }
        
        if(carry>0){
            cout<<"going ";
            if(longer){
                cout<<"here ";
                longer->next = new ListNode(carry);
            }else{
                cout<<"not here ";
                prev->next=new ListNode(carry);
            }

        }
        
        
        
        return reverse(newHead).first;
        
    }
};