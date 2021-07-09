// { Driver Code Starts
// C program to delete a given key from
// linked list.
#include <bits/stdc++.h>
using namespace std;

/* structure for a node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *pre = NULL;

/* Function to delete a given node from the list */
//void deleteNode(struct Node *head, int key);
void deleteNode(Node **head, int data);
void reverse(Node **head);

/* Function to reverse the linked list */
//static void reverse(struct Node** head_ref);

/* Function to insert a node at the beginning of
a Circular linked list */

void push(struct Node **head_ref, int data)
{
    // Create a new node and make head as next
    // of it.

    struct Node *curr = new Node(data);

    curr->next = curr;

    if (*head_ref == NULL)
    {
        *head_ref = curr;
        curr->next = *head_ref;
        pre = *head_ref;
    }
    else
    {
        curr->next = *head_ref;
        pre->next = curr;
        pre = pre->next;
    }
}

/* Function to print nodes in a given
circular linked list */
void printList(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    else
        cout << "empty" << endl;

    printf("\n");
}
/* Driver program to test above functions */
int main()
{

    /* Initialize lists as empty */
    int t, a, delnode;
    cin >> t;
    while (t--)
    {
        pre = NULL;
        Node *head = NULL;

        int n;
        cin >> n;
        while (n--)
        {
            cin >> a;
            push(&head, a);
        }
        /* Created linked list will be 2->5->7->8->10 */
        cin >> delnode;

        deleteNode(&head, delnode);

        reverse(&head);

        printList(head);
    }
    return 0;
}
// } Driver Code Ends

/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
        return;

    // If the list contains only a single node
    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *curr = *head;
    while (curr && curr->next->data != key)
        curr = curr->next;

    auto temp = curr->next;
    curr->next = temp->next;
    // free temp;

    // Your code goes here
}

/* Function to reverse the linked list */
void reverse(struct Node **head)
{
    Node *curr = *head;
    bool flag = false;
    Node *first = *head;
    Node *prev = NULL;
    Node *temp = NULL;
    while (curr != first || !flag)
    {
        flag = true;
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    first->next = prev;
    *head = (first)->next;
    first = prev;
    // cout<<temp->next->next->next->data<<" \n";
    // cout<<temp->next->next->next->next->data<<" \n";
    // cout<<prev->next->data;
    // head=prev*;
    // first->next=temp;

    // Your code goes here
}