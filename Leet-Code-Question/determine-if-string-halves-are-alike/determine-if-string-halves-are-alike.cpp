class Solution {
public:
    bool checkVowel(char c){
        switch (c){
            case 'a':
                return true;
                break;
            case 'e':
                return true;
                break;
            case 'i':
                return true;
                break;
            case 'o':
                return true;
                break;
            case 'u':
                return true;
                break;
                
            default:
                return false;
        }
        
    }
    
    bool halvesAreAlike(string s) {
        int length = s.length();
        string firstHalf = s.substr(0,length/2);
        string secondHalf = s.substr(length/2,length-1);
        
        cout<<firstHalf<<" "<<secondHalf;
        
        int count1=0;
        for(auto a:firstHalf){
            if(checkVowel(tolower(a))){
                count1++;
            }
            
        }
        int count2=0;
        for(auto a:secondHalf){
            if(checkVowel(tolower(a))){
                count2++;
            }
        }
        
        return count1==count2;
    }
};