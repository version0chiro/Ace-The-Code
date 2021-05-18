#include <bits/stdc++.h>

using namespace std;


class Edge{
    public:
        int src,dest,weight;
};

class Graph{
    public:
    int V,E;

    Edge* edge;
};

Graph* createGraph(int V,int E){
    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;

    graph->edge = new Edge[E];

    return graph;
}

class subset{
    public:
        int parent;
        int rank;
};

int find(subset subsets[],int i){
    if(subsets[i].parent!=i)
        subsets[i].parent = find(subsets,subsets[i].parent);

    return subsets[i].parent;
}

void union(subset subsets[],int x,int y){

    int xroot = find(subsets,x);
    int yoot = find(subsets,y);

    if(subsets[xroot].rank<subsets[yroot].rank){
        subsets[xroot].parent = yroot;

    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    else{
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int main(){



    return 0;
}