class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.size()==0){
            return 1;
        }
        unordered_map<int,int> m;
        unordered_map<int,int> m2;
        for(auto a:trust){
            m[a[1]]++;
            m2[a[0]]++;
        }
        
        for(auto p:m){
            if(p.second==n-1 && m2[p.first]==0){
                return p.first;
            }
        }
        
        return -1;
    }
};