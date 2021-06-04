// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(string S,int i,int j,bool isTrue){
        
         if (i > j)
        return false;
        if (i == j) {
            if (isTrue == 1)
                return S[i] == 'T';
            else
                return S[i] == 'F';
        }
        
        int ans=0;
        
        for(int k=i+1;k<j;k=k+2){
            int lT = solve(S,i,k-1,true);
            int lF = solve(S,i,k-1,false);
            
            int rT = solve(S,k+1,j,true);
            int rF = solve(S,k+1,j,false);
            
            if(S[k]=='&'){
                if(isTrue){
                    ans=ans+lT*rT;
                }else{
                    ans=ans+lF*rF+lT*rF+lF*rT;
                }
            }
            else if(S[k]=='|'){
                if(isTrue){
                    ans=ans+lT*rT+lT*rF+lF*rT;
                }else{
                    ans=ans+lF*rF;
                }
            }else if(S[k]=='^'){
                if(isTrue){
                    ans=ans+lT*rF+rT*lF;
                }else{
                    ans=ans+lT*rT+rF*lF;
                }
            }
        }
        
        return ans;
    }
    int countWays(int N, string S){
        
        return solve(S,0,S.size()-1,true);
        // code here
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends