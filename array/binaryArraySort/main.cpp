// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array
class Solution
{
public:
    vector<int> SortBinaryArray(vector<int> binArray)
    {
        // Your code goes here
        int zeroCount = 0;
        int oneCount = 0;

        for (auto a : binArray)
        {
            if (a)
            {
                oneCount++;
            }
            else
            {
                zeroCount++;
            }
        }

        int i = 0;
        while (zeroCount)
        {
            binArray[i] = 0;
            i++;
            zeroCount--;
        }

        while (oneCount)
        {
            binArray[i] = 1;
            i++;
            oneCount--;
        }

        return binArray;
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
        vector<int> binArray(n);

        for (int i = 0; i < n; i++)
            cin >> binArray[i];
        Solution ob;
        vector<int> result = ob.SortBinaryArray(binArray);
        for (int i = 0; i < n; i++)
            cout << result[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends