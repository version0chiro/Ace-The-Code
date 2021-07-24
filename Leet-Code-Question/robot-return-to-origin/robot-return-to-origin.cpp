class Solution {
public:
    
    bool judgeCircle(string moves) {
        unordered_map<char,pair<int,int>> m;
        
        m['U']={0,1},m['D']={0,-1},m['L']={-1,0},m['R']={1,0};
        
        int x=0,y=0;
        
        for(auto a:moves){
            x+=m[a].first;
            y+=m[a].second;
        }
        
        return x==0 && y==0;
    }
};