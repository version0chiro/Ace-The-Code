// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> m,int i,int j,int n,string s,vector<string> &sV){
        if(i<0|| j<0 ||  i>=n || j>=n){
            return;
        }
        cout<<m[i][j]<<"\n";
        if( m[i][j]==0){
            return;
        }
        
        cout<<i<<" "<<j<<"\n";
        if(i==n-1 && j==n-1){
            sV.push_back(s);
            return;
        }
        solve(m,i,j+1,n,s+"R",sV);
        solve(m,i+1,j,n,s+"D",sV);
        solve(m,i,j-1,n,s+"L",sV);
        solve(m,i-1,j,n,s+"U",sV);
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int i=0,j=0;
        vector<string> sV;
        solve(m,i,j,n,"",sV);
        
        return sV;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends