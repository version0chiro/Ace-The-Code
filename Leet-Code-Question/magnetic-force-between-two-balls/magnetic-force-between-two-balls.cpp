class Solution {
public:
    bool check(vector<int> position,int m,int mid,int len){
        mid--;
        int pos1=position[0];
        for(int i=1;i<len;i++){
            if(position[i]-pos1>=m){
                pos1=position[i];
                mid--;
                
                if(mid<=0){
                    return true;
                        
                }
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& position, int m) {        
        sort(position.begin(),position.end());
        
        int start =0;
        
        int maxForce = position.back() - position.front();
        
        int len = position.size();
        
        int best=0;
        
        while(start<=maxForce){
            int mid = start + (maxForce-start)/2;
            if(check(position,mid,m,len)){
                best = mid;
                // cout<<"changed to "<<mid<<endl;
                start = mid+1;
            }else{
                maxForce=mid-1;
            }
            
            
        }
        
        return best;
    }
};