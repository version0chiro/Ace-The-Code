/*
* Please read the description file to understand the logic behind the following.
*
 */
public class ListNode {
       int val;
       ListNode next;
       ListNode() {}
       ListNode(int val) {
           this.val = val;
       }
       ListNode(int val, ListNode next) {
           this.val = val; this.next = next;
       }
}
public class AddTwoNumbersInLL{
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode list1=l1, list2=l2,curr;
        ListNode resultNode=new ListNode(0);
        curr=resultNode;
        int carry=0;
        while(list1!=null || list2!=null)
        {
            int sum=carry+(list1!=null ?list1.val:0)+(list2!=null?list2.val:0);
            carry=sum/10;
            curr.next=new ListNode(sum%10);
            curr=curr.next;
            if(list1!=null)
                list1=list1.next;
            if(list2!=null)
                list2=list2.next;
        }
        if(carry>0)
            curr.next=new ListNode(carry);
        return resultNode.next;
    }
}