#include <bits/stdc++.h>

using namespace std;

class Edge
{
public:
    int src, dest;
};

class Graph
{
public:
    int V, E;
    Edge *edge;
};

Graph *createGraph(int V, int E)
{
    Graph *g = new Graph;
    g->V = V;
    g->E = E;

    g->edge = new Edge[g->E * sizeof(Edge)];

    return g;
}

int find(int parent[],int i){
    if(parent[i]==-1){
        return i;
    }
    return find(parent,parent[i]);
}

void Union(int parent[],int x,int y){
    parent[x]=y;
}

bool isCycle(Graph* graph){
    int* parent = new int[graph->V*sizeof(int)];
    memset(parent,-1,sizeof(int)*graph->V);

    for(int i=0;i<graph->E;i++){
        int x = find(parent,graph->edge[i].src);
        int y = find(parent,graph->edge[i].dest);

        if(x==y) return true;

        Union(parent,x,y);
    }

    return false;
}

int main()
{
    int V = 3, E = 3;
    Graph *graph = createGraph(V, E);

    // add edge 0-1
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;

    // add edge 1-2
    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;

    // add edge 0-2
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;

    if (isCycle(graph))
        cout << "graph contains cycle";
    else
        cout << "graph doesn't contain cycle";

    return 0;
}