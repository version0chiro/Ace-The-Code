class Solution {
public:
    void solve(vector<vector<int>>& image,int x,int y,int newColor,int baseColor){
        // cout<<x<<" "<<y<<endl;
        if(x>=image.size() || y>=image[0].size() || x<0 || y<0){
            return;
        }
        
        if(image[x][y]==baseColor){
            image[x][y]=newColor;
        }else{
            return;
        }
        
        solve(image,x+1,y,newColor,baseColor);
        solve(image,x,y+1,newColor,baseColor);
        solve(image,x-1,y,newColor,baseColor);
        solve(image,x,y-1,newColor,baseColor);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc]){
            return image;
        }
        solve(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};