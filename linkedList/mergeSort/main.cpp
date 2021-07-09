// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    pair<Node*,Node*> split(Node* head){
        Node* fast=head->next;
        Node* slow=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow = slow->next;
        }
        
        Node* a = head;
        Node* b = slow->next;
        slow->next=NULL;
        return {a,b};
        
    }
    
    Node* merge(Node* a,Node* b){
        Node* result=NULL;
        if(!a) return b;
        else if(!b) return a;
        
        if(a->data<=b->data){
            result=a;
            result->next = merge(a->next,b);
        }else{
            result=b;
            result->next = merge(a,b->next);
        }
        
        return result;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next) return head;
        Node* a;
        Node* b;
        
        auto p = split(head);
        
        a=p.first;
        b=p.second;
        
        a=mergeSort(a);
        b=mergeSort(b);
        
        
        return merge(a,b);
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends