class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> m;
        
        for(auto a:s){
            m[a]++;
        }
        for(auto a:t){
            if(m[a]==0){
                return a;
            }else{
                m[a]--;
            }
        }
        
        return 'a';
    }
};