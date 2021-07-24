class Solution {
public:
    bool static cmp(vector<int> a,vector<int> b){
        if(a[0]<b[0]) return true;
        
        else return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        
        
        
        vector<vector<int>> ans;
        
        ans.push_back({intervals[0][0],intervals[0][1]});
        
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]<=intervals[i][1] && ans.back()[1]>=intervals[i][0]){
                ans.back()[1]=intervals[i][1];
                // end=intervals[i][1];
            }else if(intervals[i][0]>ans.back()[1]){
                ans.push_back({intervals[i][0],intervals[i][1]});
                // start=intervals[i][0];
                // end=intervals[i][1];
            }
        }
        
        
            
        return ans;
    }
};