class Solution {
public:
      string serialize(vector<vector<int>>& mat) {
        string s;
        int m = mat.size(), n = mat[0].size();
        for(int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                s = s + to_string(mat[i][j]);
            }
            s = s + "#";
        }
        return s;
    }
    void addNeighbours(vector<vector<int>>& mat,unordered_map<string,bool>& visited,queue<vector<vector<int>>>& q){
        int m = mat.size(), n = mat[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                auto temp = mat;
                temp[i][j] = !temp[i][j];
                if(i+1<m) temp[i+1][j]=!temp[i+1][j];
                if(i-1>=0) temp[i-1][j]=!temp[i-1][j];
                if(j-1>=0) temp[i][j-1]=!temp[i][j-1]; 
                if(j+1<n) temp[i][j+1] = !temp[i][j+1];
                
                auto s = serialize(temp);
                if(!visited[s]){
                    visited[s]=true;
                    q.push(temp);
                }
            }
        }
    }
    
    bool good(vector<vector<int>>& mat){
        for(auto a:mat){
            for(auto b:a){
                if(b)
                    return false;
            }
        }
        
        return true;
    }
    
    int minFlips(vector<vector<int>>& mat) {
        unordered_map<string,bool> ma;
        int level = 0;
        queue<vector<vector<int>>> q;
        q.push(mat);
        
        int m = mat.size(),n = mat[0].size();
        while(q.size()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto front = q.front();q.pop();
                if(good(front)) return level;
                addNeighbours(front,ma,q);
                
            }
            level++;
        }
        
        return -1;
    }
};