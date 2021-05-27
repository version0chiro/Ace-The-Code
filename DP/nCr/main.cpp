// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int t[1001][801];

    int solve(int n, int r)
    {
        if (t[n][r] != -1)
        {
            return t[n][r];
        }
        if (r == 0)
        {
            t[n][r] = 1;
            return t[n][r];
        }
        if (r == n)
        {
            t[n][r] = 1;
            return t[n][r];
        }

        t[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);

        return t[n][r];
    }

    int nCr(int n, int r)
    {
        // code here
        memset(t, sizeof(t), -1);

        return solve(n, r);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;
    }
    return 0;
} // } Driver Code Ends