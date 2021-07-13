// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long count = 0;
    void solve(int n, int from, int to, int aux)
    {
        if (n == 1)
        {
            cout << "move disk 1 from rod " << from << " to rod " << to << "\n";
            count++;
        }
        else
        {
            solve(n - 1, from, aux, to);
            cout << "move disk " << n << " from rod " << from << " to rod " << to << "\n";
            count++;
            solve(n - 1, aux, to, from);
        }
    }
    long long toh(int N, int from, int to, int aux)
    {
        // Your code here
        solve(N, from, to, aux);

        return count;
    }
};

// { Driver Code Starts.

int main()
{

    int T;
    cin >> T; //testcases
    while (T--)
    {

        int N;
        cin >> N; //taking input N

        //calling toh() function
        Solution ob;

        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}

//Position this line where user code will be pasted.  // } Driver Code Ends