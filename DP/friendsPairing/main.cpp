// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    const unsigned int M = 1000000007;

    int t[100001];
    int solve(int n){
        if(t[n]!=-1){
            return t[n];
        }
        
        if(n>2){
            t[n]=(solve(n-1) + (solve(n-2)*(n-1)));
            return t[n]%M;
        }else{
            t[n]=n;
            return t[n];
        }
    }
    int countFriendsPairings(int n) 
    { 
        memset(t,-1,sizeof(t));
        
        return solve(n);
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends