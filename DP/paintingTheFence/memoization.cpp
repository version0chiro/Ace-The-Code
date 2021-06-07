// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long mod = 1000000007;
    vector<int> t;
    long long solve(int n,int k){
        if(n==1){
            return k;
        }
        if(n==2){
            return k*k;
        }
        if(t[n]!=-1){
            return t[n];
        }
        
        return t[n]=(k-1)*(solve(n-1,k)+solve(n-2,k))%mod;
    }
    long long countWays(int n, int k){
        // code here
        t.assign(n+1,-1);
        return solve(n,k);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends