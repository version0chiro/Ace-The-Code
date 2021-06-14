// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int multiply(int x, vector<int> &res, int res_size)
    {
        int c = 0;
        for (int i = 0; i < res_size; i++)
        {
            int p = res[i] * x + c;
            res[i] = p % 10;
            c = p / 10;
        }

        while (c)
        {
            res[res_size] = c % 10;
            c = c / 10;
            res_size++;
        }

        return res_size;
    }
    vector<int> factorial(int N)
    {
        // code here
        vector<int> res(50000);
        res[0] = 1;
        int resSize = 1;
        for (int x = 2; x <= N; x++)
        {
            resSize = multiply(x, res, resSize);
        }

        vector<int> ans;

        for (int i = resSize - 1; i >= 0; i--)
        {
            ans.push_back(res[i]);
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends