class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> sT={-1};
        int maxCount = 0;
        // int currCount=0;
        for(int i =0;i<s.length();i++){
               if(s[i]=='('){
                   sT.push_back(i);
               }else if(sT.size()==1){
                   sT[0]=i;
               }else{
                   
                   sT.pop_back();
                   maxCount = max(maxCount,i-sT.back());
               }
            }
        
        return maxCount;
    }
};