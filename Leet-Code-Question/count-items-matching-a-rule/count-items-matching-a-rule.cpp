class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int queryKey;
        int count=0;
        if(ruleKey=="type"){
            queryKey=0;
        }else if(ruleKey=="color"){
            queryKey=1;
        }else{
            queryKey=2;
        }
        
        for(auto p:items){
            if(ruleValue==p[queryKey]){
                count++;
            }
        }
        
        return count;
    }
};