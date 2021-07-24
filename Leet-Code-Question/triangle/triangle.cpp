class Solution {
public:
        vector<vector<int>> t;

    int solve(vector<vector<int>>& tri,int i,int j){
        
        if(i==tri.size() || j==tri[i].size()){
            return 10000;
        }
        if(i==tri.size()-1){
            return tri[i][j];
        }
        if(t[i][j]!=10000){
            return t[i][j];
        }
        
        int ith = solve(tri,i+1,j);
        
        int ith_one = solve(tri,i+1,j+1);
        
        
        // cout<<i<<" "<<j<<" "<<ith<<" "<<ith_one<<" "<<nextEle<<"\n";
        
        t[i][j]=(min(ith,ith_one)+tri[i][j]);
        
        return t[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        
        int n = triangle.back().size();
        t.assign(m,vector<int> (n,10000));
        
        return solve(triangle,0,0);
    }
};