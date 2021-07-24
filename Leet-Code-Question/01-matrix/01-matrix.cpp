class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
                else{
                    mat[i][j]=INT_MAX;
                }
            }
        }
        
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i= 0 ;i<4;i++){
                int new_r= curr.first + dir[i][0],new_c= curr.second + dir[i][1];
                if(new_r>=0 && new_r<n && new_c<m && new_c>=0){
                    if(mat[new_r][new_c]>mat[curr.first][curr.second] +1){
                        mat[new_r][new_c]=mat[curr.first][curr.second] +1;
                        q.push({new_r,new_c});
                    }
                }
            }
            
            
        }
        
        return mat;
    }
};