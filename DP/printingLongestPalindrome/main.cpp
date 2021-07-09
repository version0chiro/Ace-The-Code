// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string S)
    {
        // code here
        string revS = S;
        reverse(revS.begin(), revS.end());

        int n = S.size();
        int m = n;
        int t[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }
        string ans = "";
        int max = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (S[i - 1] == revS[j - 1])
                {
                    t[i][j] = 1 + t[i - 1][j - 1];
                    if (max < t[i][j])
                    {
                        string temp = S.substr(i - t[i][j], t[i][j]);
                        string revtemp = temp;
                        reverse(revtemp.begin(), revtemp.end());
                        if (revtemp == temp)
                        {
                            ans = temp;
                            max = t[i][j];
                        }
                    }
                }
                else
                {
                    t[i][j] = 0; //std::max(t[i-1][j],t[i][j-1]);
                }
            }
        }

        // int i=n,j=n;
        // while(i!=0 && j!=0){
        //     if(S[i-1]==revS[j-1]){
        //         ans=ans+S[i-1];
        //         i--;
        //         j--;
        //     }
        //     else{
        //         if(t[i-1][j]>t[i][j-1])
        //             i--;
        //         else
        //             j--;
        //     }
        // }

        // cout<<t[n][n];

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
        string S;
        cin >> S;

        Solution ob;
        cout << ob.longestPalin(S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends