class Solution {
public:
    vector<vector<int>> t;
    
    int solve(int k,int n){
        if(n==1 || n==0 || k==1){
            return n;
        }
        
        if(t[k][n]!=-1){
            return t[k][n];
        }
        
        int ans=INT_MAX;
        int l=1; int r= n;
        while(l<=r){
            int mid = (r+l)/2;
            int temp1=solve(k-1,mid-1);
            int temp2 = solve(k,n-mid);
            int temp = max(temp1,temp2);
            if(temp1<temp2){
                l=mid+1;
            }else{
                r=mid-1;
            }
            ans=min(1+temp,ans);
        }
//         for(int j=1;j<=n;j++){
//             int temp1,temp2;
//             if(t[k-1][j-1]!=-1){
//                 temp1=t[k-1][j-1];
//             }else{
//                 temp1=solve(k-1,j-1);
//                 t[k-1][j-1]=temp1;
//             }
//             if(t[k][n-j]!=-1){
//                 temp1=t[k][n-j];
//             }else{
//                 temp1=solve(k,n-j);
//                 t[k][n-j]=temp1;
//             }
            
//             int temp = 1 + temp1+temp2;
            
//             ans = min(ans,temp);
//         }
        
        
        return t[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        t.assign(k+1,vector<int> (n+1,-1));
        
        return solve(k,n);
    }
};