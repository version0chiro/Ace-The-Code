class Solution {
public:

    vector<int> graph[5000];

    int indegree[5000] = {0};
    
    void addEdge(int u,int v){
        graph[u].push_back(v);
        indegree[v]++;
    }
    
    bool canFinishUtil(int n){
        int done = 0;
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            done++;
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto a : graph[curr])
        {
            indegree[a]--;

            if (indegree[a] == 0)
            {
                q.push(a);
                done++;
            }
        }
    }
    if (done == n)
    {
        return true;
    }
    else
    {
        return false;
    }
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto a:prerequisites){
            addEdge(a[0],a[1]);
        }
        
        return canFinishUtil(numCourses);
    }
};