// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        //code here.
        int fPointer = 0, sPointer = 0, tPointer = 0;
        vector<int> ans;
        while (fPointer < n1 && sPointer < n2 && tPointer < n3)
        {
            if (A[fPointer] == B[sPointer] && A[fPointer] == C[tPointer])
            {
                ans.push_back(A[fPointer]);
                int temp = A[fPointer];
                while (A[fPointer] == temp)
                    fPointer++;
                while (B[sPointer] == temp)
                    sPointer++;
                while (C[tPointer] == temp)
                    tPointer++;
            }
            else if (A[fPointer] <= B[sPointer] && A[fPointer] <= C[tPointer])
            {
                fPointer++;
            }
            else if (B[sPointer] <= A[fPointer] && B[sPointer] <= C[tPointer])
            {
                sPointer++;
            }
            else if (C[tPointer] <= B[sPointer] && C[tPointer] <= A[fPointer])
            {
                tPointer++;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];

        for (int i = 0; i < n1; i++)
            cin >> A[i];
        for (int i = 0; i < n2; i++)
            cin >> B[i];
        for (int i = 0; i < n3; i++)
            cin >> C[i];

        Solution ob;

        vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
        if (res.size() == 0)
            cout << -1;
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
} // } Driver Code Ends