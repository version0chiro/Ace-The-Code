class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> g[n+1];
        
        for(auto a:dislikes){
            g[a[0]].push_back(a[1]);
            g[a[1]].push_back(a[0]);
        }
        
        unordered_map<int,bool> m;
        bool currCol=0;
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(m.find(i)==m.end()){
                q.push(i);
                m[i]=currCol;
                while(q.size()){
                    int node = q.front();
                    q.pop();
                    currCol=m[node];
                    for(auto a:g[node]){
                        if(m.find(a)!=m.end() && m[a]==currCol){
                            // cout<<a<<" : "<<currCol<<"\n";
                            return false;
                        }else if(m.find(a)==m.end()){
                            q.push(a);
                            m[a]=!currCol;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};