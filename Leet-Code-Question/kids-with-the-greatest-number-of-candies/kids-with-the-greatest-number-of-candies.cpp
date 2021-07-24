class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxC=INT_MIN;
        for(auto a:candies){
            maxC=max(maxC,a);
        }
        
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=maxC){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        
        return ans;
    }
};