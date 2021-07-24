class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res =0 ;
        for(int i=1;i<rating.size();i++){
            int less[2]={},greater[2]={};
            for(int j=0;j<rating.size();j++){
                if(rating[i]<rating[j])
                    ++less[j>i];
                if(rating[i]>rating[j])
                    ++greater[j>i];
            }
            
            res+=greater[0]*less[1]  + less[0]*greater[1];
        }
        
        return res;
    }
};