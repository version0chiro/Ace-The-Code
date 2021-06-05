//approch:
// alternatively compare the two halves of the strings recursively
// aka: The first i elements of first string with last i elements of second string && last n-i elements of first string with first n-i elements of second string
// and OR it with first i elements of first string with first i elements of second string && last n-i elements of first string with last n-i elements of second string
// make key using both strings and space between them using an unordered_map as dp table

class Solution {
public:
    unordered_map<string,int> t;
    bool solve(string s1,string s2){
        if(s1==s2){
            return true;
        }
        if(s1.length()<=1) return false;
        
        
        int n = s1.length();
        
        string key=s1+" "+s2;
        
        if(t.find(key)!=t.end()){
            return t[key];
        }
            
        bool flag=false;
        for(int i=1;i<n;i++){
            if((solve(s1.substr(0,i),s2.substr(n-i,i)) &&  solve(s1.substr(i,n-i),s2.substr(0,n-i))) || (solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-1)))){
                flag=true;
                break;
            }
        }
        
        return t[key]=flag;
    }
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1.length()<1){
            return true;
        }
        return solve(s1,s2);
    }
};