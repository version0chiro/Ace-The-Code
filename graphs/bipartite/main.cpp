#include <bits/stdc++.h>

using namespace std;

bool isBipartite(int V,vector<int> adj[]){
   vector<int> col(V,-1);

   queue<pair<int,int>> q;

   for(int i=0;i<V;i++){
       if(col[i]==-1){
           q.push({i,0});
           col[i]=0;

           while(!q.empty()){
               auto temp = q.front();
               q.pop();
               int v = temp.first;
               int c = temp.second;

               for(auto a:adj[v]){
                   if(col[a]==c){
                       return false;
                   }
                   if(col[a]==-1){
                       col[a]= (c)?0:1;
                       q.push({a,col[a]});
                   }
               }
           }
       }
   } 

   return true;

}
int main()
{
    int V, E;
    V = 4, E = 8 ;
    vector<int> adj[V];
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    bool ans = isBipartite(V, adj);
    //returns 1 if bipatite graph is possible
    if (ans)
        cout << "Yes\n";
    //returns 0 if bipartite graph is not possible
    else
        cout << "No\n";

    return 0;
    return 0;
}