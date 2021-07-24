class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,bool> m;
        bool currCol=0;
        
        queue<int> q;
        for(int i=0;i<graph.size();i++){
            if(m.find(i)==m.end()){
                        q.push(i);
        m[i]=currCol;
        while(q.size()){
            int node = q.front();
            currCol=m[node];
            q.pop();
            
            for(auto a:graph[node]){
                if(m.find(a)!=m.end() && m[a]==m[node]){
                    return false;
                }else if(m.find(a)==m.end()){
                    m[a]=!currCol;
                    q.push(a);
                }
            }
            // cout<<"\n";
            
        }

            }
        }        
        return true;
    }
};