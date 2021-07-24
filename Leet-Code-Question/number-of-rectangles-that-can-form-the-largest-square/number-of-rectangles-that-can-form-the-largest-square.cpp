class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> m;
        
        int maxCount = 0;
        int maxLen = 0;
        
        for(auto a:rectangles){
            
            m[min(a[0],a[1])]++;
            if(min(a[0],a[1])>maxLen){
                maxLen = min(a[0],a[1]);
                // maxCount = m[min(a[0],a[1])];
            }
        }
        
        return m[maxLen];
    }
};