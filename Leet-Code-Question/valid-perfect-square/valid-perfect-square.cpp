class Solution {
public:
    bool isPerfectSquare(int x) {
        int start=1,end=x;
        
        
        while(start<=end){
            double mid= start+(end-start)/2;
            if(double(mid)-double(x/mid)==0){
                // cout<<(double)x/mid<<" "<<double(mid);
                return true;    
            } 
            
            
            if(mid<=x/mid) start=mid+1;
            
            else end=mid-1;
        }
        
        return false;
    }
};