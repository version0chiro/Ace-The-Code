// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.

bool isSafe(bool graph[101][101],int v,int colors[],int c,int V){
    
    for(int i=0;i<V;i++){
        if(graph[v][i] && colors[i]==c) return false;
    }
    
    return true;
}

bool graphColoringUtil(bool graph[101][101],int m,int V,int colors[],int v){
    if(v==V){
        return true;
    }
    
    for(int i=1;i<=m;i++){
        
        if(isSafe(graph,v,colors,i,V)){
            colors[v]=i;
            if(graphColoringUtil(graph,m,V,colors,v+1)){
                return true;
                
            }
            colors[v]=0;
        }
    }
    
    return false;
}
bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int colors[V];
    
    for(int i=0;i<V;i++){
        colors[i]=0;
    }
    
    
    return graphColoringUtil(graph,m,V,colors,0);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends