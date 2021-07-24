class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp_MAP(m + 1, vector<int>(n + 1));
        for(auto a:strs){
            int zeroCount = count(begin(a), end(a), '0');
            int oneCount = size(a) - zeroCount;
            
            for(int i = m;i>=zeroCount;i--){
                for(int j=n;j>=oneCount;j--){
                    dp_MAP[i][j] = max(dp_MAP[i][j],dp_MAP[i-zeroCount][j-oneCount]+1);
                }
            }
            
        }
        
      return dp_MAP[m][n];  
    }
};