class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto a:times){
            adj[a[0]].push_back({a[1],a[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distTo(n+1,INT_MAX);
        int maxE = INT_MIN;
        distTo[k]=0;
        pq.push({0,k});
        bool visit[n+1];
        memset(visit, false, sizeof(visit));
        while(pq.size()){
            int dist  = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            visit[prev]=true;
            for(auto it:adj[prev]){
                int next = it.first;
                int net_dist = it.second;
                
                if(visit[next]==false &&  distTo[next]>=distTo[prev]+net_dist){
                    distTo[next]=distTo[prev]+net_dist;
                    pq.push({distTo[next],next});
                }
            }
            
        }
        for(int i=1;i<distTo.size();i++){
            if(distTo[i]==INT_MAX) return -1;
            maxE = max(maxE,distTo[i]);
        }
        if(maxE==INT_MIN) return -1;
        return maxE;
    }
};