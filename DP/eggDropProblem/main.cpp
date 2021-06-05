// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    vector<vector<int>> t;
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.

    int solve(int n, int k)
    {
        if (k == 0 || k == 1)
        {
            return k;
        }
        if (n == 1)
        {
            return k;
        }

        if (t[n][k] != -1)
            return t[n][k];

        int ans = INT_MAX;

        for (int j = 1; j <= k; j++)
        {
            int temp = 1 + max(solve(n - 1, j - 1), solve(n, k - j));

            ans = min(temp, ans);
        }

        return t[n][k] = ans;
    }
    int eggDrop(int n, int k)
    {
        t.assign(n + 1, vector<int>(k + 1, -1));

        return solve(n, k);
        // your code here
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        //calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends