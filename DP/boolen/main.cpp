// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[1001][1001][2];
    int solve(string S,int i,int j,int isTrue){
        
         if (i > j)
        return false;
        
        if (i == j) {
            if (isTrue == 1)
                return S[i] == 'T';
            else
                return S[i] == 'F';
        }
        
        if(t[i][j][isTrue]!=-1){
            return t[i][j][isTrue];
        }
        int ans=0;
        
        for(int k=i+1;k<j;k=k+2){
            int lT,lF,rT,rF;
            
            if(t[i][k-1][1]!=-1)
                lT=t[i][k-1][1];
            else
                lT = solve(S,i,k-1,1);
            
            if(t[i][k-1][0]!=-1)
                lF=t[i][k-1][0];
            else
                lF = solve(S,i,k-1,0);
            
            if(t[k+1][j][1]!=-1)
                rT=t[k+1][j][1];
            else
                rT = solve(S,k+1,j,1);
            
            if(t[k+1][j][0]!=-1)
                rF=t[k+1][j][0];
            else
                rF = solve(S,k+1,j,0);
            
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
            t[i][j][isTrue] = ans;
        }
        
        return t[i][j][isTrue] = ans%1003;
    }
    int countWays(int N, string S){
        
        memset(t,-1,sizeof(t));
        return solve(S,0,S.size()-1,1);
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