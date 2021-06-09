
// Init a start at zero and make a new variable for keeping the minimum value. Sort the array,
// now traverse the array with start incremeneting till start+m-1<n. Find min between the variable for minimum and the current difference between the start+m and start. return the variable in the end.



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        //code
        sort(a.begin(), a.end());

        int start = 0;
        int end = m;

        int minDist = INT_MAX;
        while (start < n - m + 1)
        {
            // cout<<a[start]<<" "<<a[start+m-1]<<"\n";
            if (minDist > a[start + m - 1] - a[start])
            {
                minDist = a[start + m - 1] - a[start];
            }
            start++;
        }

        return minDist;
    }
};

// { Driver Code Starts.
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a;
        long long x;
        for (long long i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        long long m;
        cin >> m;
        Solution ob;
        cout << ob.findMinDiff(a, n, m) << endl;
    }
    return 0;
} // } Driver Code Ends