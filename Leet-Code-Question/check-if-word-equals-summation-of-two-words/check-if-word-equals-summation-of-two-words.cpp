class Solution {
public:
    
    int convertToInt(string word){
        int num=0;
        int count=0;
        for(int j=word.size()-1;j>=0;j--){
            num+=((int)word[j]-97)*(pow(10,count));
            count++;
        }
        return num;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        
        
        return convertToInt(firstWord)+convertToInt(secondWord)==convertToInt(targetWord);
        // return true;
    }
};