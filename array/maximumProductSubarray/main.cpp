// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n)
	{
		// code here
		long long l = 1, r = 1;
		long long maxV = INT_MIN;
		for (int i = 0; i < n; i++)
		{
			l == 0 ? l = arr[i] : l = l * arr[i];
			r == 0 ? r = arr[n - i - 1] : r = r * arr[n - i - 1];
			maxV = max(maxV, max(l, r));
		}
		return maxV;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, i;
		cin >> n;
		int arr[n];
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		Solution ob;
		auto ans = ob.maxProduct(arr, n);
		cout << ans << "\n";
	}
	return 0;
} // } Driver Code Ends