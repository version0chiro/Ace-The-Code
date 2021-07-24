class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int numberOfString = strs.size();
        if(numberOfString<1){
            return "";
        }
        int wordsInNumber = strs[0].size();
        int counter=0;
        string ans="";
        bool checkFlag=true;
        for(int j=0;j<wordsInNumber;j++){
            for(int i=0;i<numberOfString-1;i++){
                checkFlag = checkFlag && (strs[i][j]==strs[i+1][j]);                
            }
            if(checkFlag){
                ans=ans+strs[0][j];
            }
        }
        
        return ans;
    }
};