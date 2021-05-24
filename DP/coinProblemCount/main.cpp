// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int t[1001][1001];
    long long int solve(int S[],int m,int n,long long int &count){
        if(t[m][n]!=-1){
            return t[m][n];
        }
        if(n==0){
            t[m][n]=1;
            return t[m][n];
        }
        if(n<0 || m-1<0){
            t[m][n]=0;
            return t[m][n];
        }
        
        if(S[m-1]<=n){
            t[m][n]=count+solve(S,m,n-S[m-1],count)+solve(S,m-1,n,count);
            // cout<<" goes here"<<endl;
            return t[m][n];
        }
        else{
            
        t[m][n]=count+solve(S,m-1,n,count);
        return t[m][n];
        }
        
        
    }
    long long int count( int S[], int m, int n )
    {   
        long long int count=0;
        
        memset(t,-1,sizeof(t));
        
        return solve(S,m,n,count);
        
        // return count;
        //code here.
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends