class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>> m;
        
        for(auto a:paths){
            m[a[0]].push_back(a[1]);
            if(m.find(a[1])==m.end())
                m[a[1]]={};
        }
        
        
        for(auto a:m){
            if(!a.second.size()) return a.first;
        }
        
        
        return "";
    }
};