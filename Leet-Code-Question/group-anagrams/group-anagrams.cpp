class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> h_map;
        
        for(auto p:strs){
            vector<int> tempArray (26,0);
            for(auto a:p){
                tempArray[a-'a']++;
            }
            h_map[tempArray].push_back(p);
        }
        
        for(auto p:h_map){
            ans.push_back(p.second);
        }
        
        return ans;
    }
};