// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

    // Function to find the trapped water between the blocks.
public:
    int trappingWater(int arr[], int n)
    {
        // Code here
        int total = 0;

        int left = 0, right = n - 1;

        int maxWall = min(arr[left], arr[right]);

        while (left < right)
        {
            if (arr[right] < arr[left])
            {
                total += max(maxWall - arr[right], 0);
                maxWall = max(arr[right], maxWall);
                right--;
            }
            else
            {
                total += max(maxWall - arr[left], 0);
                maxWall = max(arr[left], maxWall);
                left++;
            }
        }

        return total;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends