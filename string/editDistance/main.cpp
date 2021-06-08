//Approch: 
// Done with DP: int the matrix with n+1 and m+1 where n and m are the length of s and t respectively. 
// Now init the value at t[0][0] as 0 because both strings are equal. 
// Now from i=0 to n+1, place t[i][0] = I and for j=0 to m+1 place t[0][j]=j.
// Now traverslse the matrix from 1 to n+1 and for j= 1 to m+1. For any point where s[i-1]==t[j-1],
// take the diagonally previous element at t[i-1][j-1] and place in t[i][j] else take minimum from t[i-][j-1], t[i-1][j],t[i][j-1]. 
// return the value at t[n][m]



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string s2) {
        // Code here
        int n=s.length();
        int m=s2.length();
        
        int t[n+1][m+1];
        
        for(int i=0;i<n+1;i++){
            t[i][0]=i;
        }
        for(int i=0;i<m+1;i++){
            t[0][i]=i;
        }
        
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==s2[j-1]){
                    t[i][j]=t[i-1][j-1];
                }else{
                    t[i][j]=1+min(t[i-1][j],min(t[i-1][j-1],t[i][j-1]));
                }
            }
        }
        
        return t[n][m];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends