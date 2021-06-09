// Take two pointers for arr1 and one pointer for array 2. init i=0 and k = n-1 for arr1 pointer and j=0 for array two's pointer, now traverse the array and at any point arr1[i]>arr2[j], swap arr2[j] with arr[k] k-- j++ else do i++. At last sort both the arrays


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        // code here
        int pointer2 = 0, pointer1 = 0, k = n - 1;

        while (pointer1 <= k && pointer2 < m)
        {
            // cout<<"in";
            if (arr1[pointer1] > arr2[pointer2])
            {
                swap(arr2[pointer2], arr1[k]);

                pointer2++;
                k--;
            }
            else
            {
                pointer1++;
            }
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++)
        {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++)
        {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends