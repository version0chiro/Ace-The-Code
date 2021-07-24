class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> jMap;
        for(auto a:jewels){
            jMap[a]++;
        }
        
        int count=0;
        for(auto p:stones){
            if(jMap[p]>0){
                count++;
            }
        }
        
        return count;
    }
};