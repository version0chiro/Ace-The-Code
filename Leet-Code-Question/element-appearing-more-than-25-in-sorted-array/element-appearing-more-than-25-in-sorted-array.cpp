class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> m;
        
        for(auto a:arr){
            m[a]++;
        }
        
        double per= arr.size()*0.25;
        
        for(auto a:m){
            if(a.second>=per){
                return a.first;
            }
        }
        
        return -1;
    }
};