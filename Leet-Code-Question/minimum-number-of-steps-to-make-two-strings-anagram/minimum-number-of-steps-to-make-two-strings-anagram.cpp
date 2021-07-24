class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> hMap;
        int count=0;
        for(auto p:t){
            hMap[p]++;
        }
        
        for(auto p:s){
            if(hMap[p]==0){
                count++;
            }else{
                hMap[p]--;
            }
        }
        
        return count;
    }
};