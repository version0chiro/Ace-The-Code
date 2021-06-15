// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int sb(int arr[], int n, int x)
    {
        // Your code goes here
        int len = INT_MAX;
        int tempLen = 0;
        int i = 0;
        int j = 0;
        int sum = 0;
        while (i < n && j < n)
        {
            // cout<<" "<<arr[i]<<" ";
            if (sum <= x)
            {
                sum += arr[j];
                tempLen++;
                // cout<<" adding "<<arr[j]<<" "<<sum<<" ";
                j++;
            }
            while (sum > x)
            {
                len = min(len, tempLen);
                tempLen--;
                sum = sum - arr[i];
                // cout<<" removing "<<arr[i]<<" "<<sum<<" "<<" "<<tempLen;
                i++;
            }
        }

        return len;
    }
};

// { Driver Code Starts.

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.sb(a, n, x) << endl;
    }
    return 0;
} // } Driver Code Ends