// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum number of cuts.
    vector<vector<int>> t;
    
    int solve(int len,int n,vector<int> arr,int segs){
        
        
        if(len==0){
            // t[len][n]=segs;
            return 0;
        }
        
        if(len<0 || n==0){
            return INT_MIN; 
        }
        if(t[len][n]!=-1){
            return t[len][n];
        }
        if(len>=arr[n-1]){
            t[len][n]=max(1+solve(len-arr[n-1],n,arr,segs+1),solve(len,n-1,arr,segs));
        }else{
            t[len][n]=solve(len,n-1,arr,segs);
        }
        
        return t[len][n];
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> arr = {x,y,z};
        sort(arr.begin(),arr.end());
        t.assign(n + 1, vector<int>(4, -1));
        
        int ans= solve(n,arr.size(),arr,0);
        
        if(ans<0){
            return 0;
        }else{
            return ans;
        }
        
        //Your code here
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends