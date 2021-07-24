class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()<1){
            return 0;
        }
        
        cout<<haystack[5];
        int needleLength=needle.length();
        cout<<needleLength;
        int countLength=0;
        for(int i=0;i<haystack.length();i++){
            cout<<haystack[i];
            if(haystack[i]==needle[0]){
                while(countLength<needleLength){
                    if(haystack[i+countLength]!=needle[countLength]){
                        break;
                    }
                    countLength++;
                }
                if(countLength==needleLength){
                    return i;
                }
                countLength=0;
            }
        }
        return -1;
    }
};