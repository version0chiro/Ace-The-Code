// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int sum = 0;
        unordered_map<int, int> m;
        int tempSum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (m.find(sum) != m.end())
            {
                return true;
            }
            m[sum]++;
            if (sum == 0 || arr[i] == 0)
            {
                return true;
            }
        }

        return false;

        //Your code here
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        if (obj.subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
} // } Driver Code Ends