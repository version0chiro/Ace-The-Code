class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int N=arr.size();
        if(N==0) return 0;
        set<int> s;
      for(int i=0;i<N;i++){
          s.insert(arr[i]);
      }
      
      int ans=INT_MIN;
      int y;
      for(auto a:s){
          if(s.find(a-1)==s.end()){
              y = a+1;
              while(s.find(y)!=s.end()){
                  y++;
              }
              ans=max(ans,y-a);
          }
      }
      
      return ans;
    }
};