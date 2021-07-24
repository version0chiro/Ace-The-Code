class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        set<int> secondList;
       
       for(int i=0;i<n;i++){
           secondList.insert(a[i]);
       }
       
       vector<int> sorted;
       for(auto a:secondList){
            sorted.push_back(a);
       }
       
       int m = sorted.size();
       
       if(m==0){
           return 0;
       }
       
       int t[n+1][m+1];
       
       memset(t,0,sizeof(t));
       
       for(int i=1;i<n+1;i++){
           for(int j=1;j<m+1;j++){
               if(a[i-1]==sorted[j-1]){
                   t[i][j]=1+t[i-1][j-1];
               }
               else{
                   t[i][j]=max(t[i-1][j],t[i][j-1]);
               }
           }
       }
       
       return t[n][m];
    }
};