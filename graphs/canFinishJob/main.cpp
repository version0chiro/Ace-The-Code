#include <bits/stdc++.h>

using namespace std;

#define maxN 100

vector<int> graph[maxN];

int indegree[maxN] = {0};

void addEdge(int u, int v)
{
    graph[u].push_back(v);
    indegree[v]++;
}

void canFinish(int n)
{
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
        cout << "Can finish all the jobs"
             << "\n";
    }
    else
    {
        cout << " Can not finish the jobs \n";
    }
}

int main()
{
    int n = 4;
    addEdge(1, 0);
    addEdge(0, 1);
    addEdge(2, 1);
    addEdge(3, 2);

    canFinish(n);
    return 0;
}