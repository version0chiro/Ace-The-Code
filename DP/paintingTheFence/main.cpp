// { Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long countWays(int n, int k)
    {
        // code here
        long long t[n + 1];
        long long mod = 1000000007;

        t[1] = k;
        t[2] = k * k;
        for (int i = 3; i <= n; i++)
        {
            t[i] = (k - 1) * (t[i - 1] + t[i - 2]) % mod;
        }

        return t[n];
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        cout << ob.countWays(n, k) << endl;
    }
    return 0;
} // } Driver Code Ends