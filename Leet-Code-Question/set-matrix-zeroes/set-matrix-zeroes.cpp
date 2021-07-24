class Solution {
public:
    void solve(vector<vector<int>>& matrix,vector<pair<int,int>> m){
        int cLength = matrix.size();
        int rLength = matrix[0].size();
        for(auto p:m){
            int r=p.first;
            int c=p.second;
            for(int i=0;i<cLength;i++){
            
                matrix[i][r]=0;
            // matrix[c][i]=0;
            }
        for(int i=0;i<rLength;i++){
            // cout<<matrix[c][i]<<"\n";
                matrix[c][i]=0;
        }

        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int cLength = matrix.size();
        int rLength = matrix[0].size();
        vector<pair<int,int>> m;
        for(int i=0;i<cLength;i++){
            for(int j=0;j<rLength;j++){
                if(matrix[i][j]==0){
                    m.push_back(make_pair(j,i));
                    // solve(matrix,j,i);
                    // return;
                }
            }
        }
        solve(matrix,m);
    }
};