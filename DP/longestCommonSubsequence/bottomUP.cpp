// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    
    int t[1001][1001];
    //Function to find the length of longest common subsequence in two strings.
    int LCS_UTIL(int x,int y,string s1,string s2){
        if(x==0 || y==0){
            return 0;
        }
        
        if(t[x][y]!=-1){
            return t[x][y];
        }
        
        if(s1[x-1]==s2[y-1]){
            // cout<<s1[x]<<" "<<s2[y]<<"\n";
            return t[x][y]=1+LCS_UTIL(x-1,y-1,s1,s2);
        }else{
            return t[x][y]=max(LCS_UTIL(x,y-1,s1,s2),LCS_UTIL(x-1,y,s1,s2));
        }
    }
    int lcs(int x, int y, string s1, string s2)
    {
        memset(t,-1,sizeof(t));
        // your code here
        return LCS_UTIL(x,y,s1,s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends