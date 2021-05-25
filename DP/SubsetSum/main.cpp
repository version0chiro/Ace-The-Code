class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int s=sizeof(arr)/sizeof(arr[0]);
        
        bool t[s+1][N+1];
        
        for(int j=0;j<N+1;j++){
            t[0][j]=false;
            
        }
        
        for(int i=0;i<s+1;i++){
            t[i][0]=true;
        }
        
        for(int i=1;i<s+1;i++){
            for(int j=1;j<N+1;j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        return t[s][N];
    }
};