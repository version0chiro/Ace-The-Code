class Solution {
public:
    int maxArea(vector<int>& height) {
        int r=height.size()-1;
        int l = 0;
        
        int maxVal = INT_MIN;
        while(l<r){
            int area = (r-l)*(min(height[l],height[r]));
            
            
            maxVal = max(maxVal,area);
            
            if(height[l]>height[r]){
                r--;
            }else{
                l++;
            }
        }
        
        return maxVal;
    }
};