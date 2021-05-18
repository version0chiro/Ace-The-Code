#include <bits/stdc++.h>

using namespace std;

struct Interval
{
    int start;
    int end;
};

struct ITNode
{
    Interval *i;
    int max;
    ITNode *left, *right;
};

ITNode * newNode(Interval i)
{
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.end;
    temp->left = temp->right = NULL;


}

ITNode *insert(ITNode *root, Interval interval)
{
    if (root == NULL)
        return newNode(interval);

    int lower = root->i->start;

    if (lower > interval.start)
    {
        root->left = insert(root->left, interval);
    }
    else
    {
        root->right = insert(root->right, interval);
    }

    if (root->max < interval.end)
        root->max = interval.end;

    return root;
}

bool doOverlap(Interval i1, Interval i2)
{
    if (i1.start < i2.end && i1.end > i2.start)
        return true;
    return false;
}

Interval *overlapSearch(ITNode *root, Interval i)
{
    if (root == NULL)
        return NULL;

    if (doOverlap(*(root->i), i))
        return root->i;

    if (root->left && root->left->max >= i.start)
        return overlapSearch(root->left, i);

    return overlapSearch(root->right, i);
}

void printConflicting(Interval appt[], int n)
{
    ITNode *root = NULL;
    root = insert(root, appt[0]);

    for (int i = 1; i < n; i++)
    {
        Interval *res = overlapSearch(root, appt[i]);
        if (res != NULL)
        {
            cout << "[" << appt[i].start << "," << appt[i].end << "] [" << res->start << "," << res->end << "]\n";
        }

        root = insert(root, appt[i]);
    }
}

int main()
{
    Interval appt[] = {{1, 5}, {3, 7}, {2, 6}, {10, 15}, {5, 6}, {4, 100}};
    int n = sizeof(appt) / sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
    return 0;
}