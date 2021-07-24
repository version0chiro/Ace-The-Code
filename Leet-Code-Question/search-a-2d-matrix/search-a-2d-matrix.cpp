class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=-1;
        int iLimit=matrix.size();
        cout<<iLimit<<" ";
        while(i+1<iLimit && matrix[i+1][0]<=target){
            if(matrix[i+1][0]==target){
                return true;
            }
            i++;
        }
        cout<<" "<<i;
        if(i==iLimit){
            
            return false;
        }
        // i=i-1;
        
        if(i<0){
            return false;
        }
        
        int j=0;
        int jLength = matrix[i].size();
        cout<<jLength<<" "<<i;
        while(j<jLength && matrix[i][j]!=target){
            
            if(matrix[i][j]>target){
                return false;
            }
            else if(matrix[i][j]==target){
                return true;
            }
            j++;
        }
        
        if(j==jLength){
            return false;
        }
        
        return true;
    }
};