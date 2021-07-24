class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        if(A.size()<3)
            return true;
        
        int VAL = A[0];
        
        for(int i=2;i<A.size();i++){
            if(VAL>A[i]){
                return false;
            }
            VAL = max(VAL,A[i-1]);
        }
        return true;
    }
};