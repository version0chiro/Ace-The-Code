// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        //code here

        vector<int> prices2;
        prices2.push_back(0);

        for (int i = 0; i < n; i++)
        {
            // cout<<price[i]<<" ";
            prices2.push_back(price[i]);
        }
        int m = prices2.size();

        int t[m + 1][n + 1];

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                t[i][j] = 0;
            }
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (j - i < 0)
                {

                    t[i][j] = t[i - 1][j];
                }
                else
                {
                    t[i][j] = max(t[i - 1][j], prices2[i] + t[i][j - i]);
                }
            }
        }

        return t[m][n];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
} // } Driver Code Ends