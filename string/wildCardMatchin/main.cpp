// approch:

// Used dp, initalize a matrix  with size of n+1,m+1 where n and m are the length of the wild string and pattern
// string respectively.  Set all elements to 0 using memset.
// Set first element to 1 as they match , aka both are empty string: "" "". 
//Loop the dimension of wild and for all values of * place true as it matches to "" as per question.
// Now loop through the array from 1 to n+1 and from 1 to m+1, if the elements at wild[i-1]==pattern[j-1], set t[i][j] = t[i-1][j-1]. 
//this is also true if wild[i-1] is '?' , if wild[i-1] is equal to *,  take the or of i-1,j and i,j-1. return the value at t[n][m] for ans


//quick note: On gfg you have to init all the places with * as 1 in the initialize col, but in leetcode you only have to do for the * that apprear in 
// the starting

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.size(),m=pattern.size();
        
        int t[n+1][m+1];
        
        memset(t,0,sizeof(t));
        
        t[0][0]=1;
        
        for(int i=1;i<n+1;i++){
            if(wild[i-1]=='*'){
                t[0][i]=1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(wild[i-1]=='?' || wild[i-1]==pattern[j-1]){
                    t[i][j]=t[i-1][j-1];
                }
                else if(wild[i-1]=='*'){
                    t[i][j]=t[i-1][j]||t[i][j-1];
                }
            }
        }
        
        return t[n][m];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends