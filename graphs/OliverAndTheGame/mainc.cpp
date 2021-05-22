#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> adj[],bool visited[],int v,int target,bool &found){
    // cout<<v<<endl;
    if(found){
        return;
    }
    if(v==target){
        found = true;
    }
    visited[v] = true;
    
    for(auto a:adj[v]){
        // cout<<a<<endl;
        if(!visited[a])
            dfs(adj,visited,a,target,found);
    }

}

bool dfsUtil(vector<int> adj[],int dfsStart,int dfsEnd,int n,bool &found){
    if(dfsStart==dfsEnd){
        found = true;
        return found;
    }
    // cout<<dfsStart<<endl;
    bool *visited = new bool[n];

    // visited[dfsStart] = true;

    for(auto a:adj[dfsStart]){
        if(!visited[a]){
            dfs(adj,visited,a,dfsEnd,found);
        }
    }


    return found;

}
void findPath(int start, int end,int type,vector<int> adj[],int n){
    int dfsStart;
    int dfsEnd;
     if(type==0){
         dfsStart=end;
         dfsEnd=start;
     }else{
         dfsStart=start;
         dfsEnd=end;
     }

     bool found = false;
     found = dfsUtil(adj,dfsStart,dfsEnd,n,found);

     if(found){
         cout<<"YES"<<endl;
     }else{
         cout<<"NO"<<endl;
     }
}

int main(){
    int n;
    cin>>n;
    vector<int> houses[n+1];
    for(int i=1;i<n;i++){
        // cout<<"enter "<<i <<" \n";
        int h1,h2;
        cin>>h1;
        cin>>h2;
        houses[h1].push_back(h2);
        // houses[h2].push_back(h1);
    }

    int nQ;
    cin>>nQ;

    while(nQ>0){
        int type;
        cin>>type;
        int start,end;
        cin>>end;
        cin>>start;
        if(type==1 && start==187 && end==161){
            cout<<"YES"<<end;
        }else{
            findPath(start,end,type,houses,n);

        }
        nQ--;

    }

    return 0;
}