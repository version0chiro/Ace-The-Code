// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	// arr[] : the input array
	// N : size of the array arr[]

	//Function to return length of longest subsequence of consecutive integers.
	int findLongestConseqSubseq(int arr[], int N)
	{
		//Your code here
		set<int> s;
		for (int i = 0; i < N; i++)
		{
			s.insert(arr[i]);
		}

		int ans = INT_MIN;
		int y;
		for (auto a : s)
		{
			if (s.find(a - 1) == s.end())
			{
				y = a + 1;
				while (s.find(y) != s.end())
				{
					y++;
				}
				ans = max(ans, y - a);
			}
		}

		return ans;
	}
};

// { Driver Code Starts.

// Driver program
int main()
{
	int t, n, i, a[100001];
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> a[i];
		Solution obj;
		cout << obj.findLongestConseqSubseq(a, n) << endl;
	}

	return 0;
} // } Driver Code Ends