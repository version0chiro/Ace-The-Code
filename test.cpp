#include <bits/stdc++.h>

using namespace std;

// 3 1 4 6             3 1 4 6
// -1       -1
void insert(int arr[], int length, int &front, int &rear, int item)
{
    if (rear == length)
    {
        cout << "overflow";
    }

    else
    {
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear=rear+1;
        }
    }

    arr[rear] = item;
}

int front_elem(int arr[], int length, int &front, int &rear)
{
    if (front == -1)
    {
        cout << "underflow";
        return -1;
    }

    else
    {
        int ans = arr[front];
        cout<<front<<" \n";
        return ans;
    }

}

void pop(int arr[], int length, int &front, int &rear)
{
    // cout<<front<<": "<<rear<<" \n";
    if (front == -1)
    {
        cout << "underflow";
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            front=front + 1;
            // rear=rear-1;
    }
}

// 3 5 6
int main()
{
    // int n;
    // cin >>n;
    int arr[4];
    int front = -1, rear = -1, length = 4;
    insert(arr, length, front, rear, 3);
    insert(arr, length, front, rear, 5);
    insert(arr, length, front, rear, 6);
    insert(arr, length, front, rear, 10);
    pop(arr, length, front, rear);
    pop(arr, length, front, rear);
    pop(arr, length, front, rear);
    insert(arr, length, front, rear, 35);
    insert(arr, length, front, rear, 15);
    insert(arr, length, front, rear, 25);
    cout << front_elem(arr, length, front, rear)<<"\n";
    pop(arr, length, front, rear);
    cout << front_elem(arr, length, front, rear);

    return 0;
}