class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        string temp="";
        for(auto a:words){
            for(auto p:a){
                temp+=morse[(int)p-97];
            }
            s.insert(temp);
            temp="";
        }
        // cout<<(int)'b';
    
    
        return s.size();
    
    
    
    }
};