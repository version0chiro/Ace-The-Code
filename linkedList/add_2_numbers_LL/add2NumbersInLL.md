## Add 2 numbers in Linked list

Problem Description:
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in **reverse order**, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.


Example 1:
Input: list1 = [2,4,3], list2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: list1 = [9,9,9,9,9,9,9], list2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


# Explanation: 
Keep track of the carry using a variable and simulate digits-by-digits sum starting from the head of list, which contains the least-significant digit.
1. used a dummy resultHead to simplify the code, initialize it with a dummy value.
2. Initialize carry variable=0
3. Iterating through both the List and adding the values till they don't reach the end. 
   3.1 sum= list1.val(if not null) + list2.val(if not null) + carry
   3.2 Update carry = sum / 10 , to add the same in the next iteration
   3.3 Create a new node with the digit value of [sum % 10] and set it to current node's next, 
        then advance current node to next => curr=curr.next
   3.4 If not null, Advance both the lists to their next element => list1.next and list2.next 
 
4. Now if both the lists reached their last node, Check if carry = 1, if so append a new node with digit 1 to the returning list.
5. Return the next element of resultHead as we have initialized the resultHead with a dummy value.
