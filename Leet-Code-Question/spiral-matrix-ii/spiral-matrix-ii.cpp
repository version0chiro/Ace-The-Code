class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> t(n,vector<int>(n,0));
        
        int pI=1;
        
        int left=0,right=n-1,bottom=n-1,top=0;
        
        int direction = 1;
        
        
        while(left<=right && top<=bottom){
            if(direction==1){
                for(int i=left;i<=right;i++) t[top][i]=pI,pI++;
                direction=2;
                top++;
            }
            
            else if(direction==2){
                for(int i=top;i<=bottom;i++) t[i][right]=pI,pI++;
                direction=3;
                right--;
            }
            
            else if(direction==3){
                for(int i=right;i>=left;i--) t[bottom][i]=pI,pI++;
                direction=4;
                bottom--;
            }
            
            else if(direction==4){
                for(int i=bottom;i>=top;i--) t[i][left]=pI,pI++;
                direction=1;
                left++;
            }
        }
        
        return t;
    }
};