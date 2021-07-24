class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sec=heights;
        sort(sec.begin(),sec.end());
        
        int count=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=sec[i]){
                count++;
            }
        }
        
        return count;
    }
};