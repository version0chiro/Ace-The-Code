class Solution {
public:
    string r1="qwertyuiop",r2="asdfghjkl",r3="zxcvbnm";
    vector<string> findWords(vector<string>& words) {
        unordered_map<char,int> m;
        for(auto a:r1){
            m[a]=1;
        }
        for(auto a:r2){
            m[a]=2;
        }
        for(auto a:r3){
            m[a]=3;
        }
        
        vector<string> ans;
        
        for(auto a:words){
            
            bool add=true;
            // cout<<tolower(a[0])<<" "<<m[a[0]]<<"\n";
            int row=m[tolower(a[0])];
            for(int i=0;i<a.size();i++){
                if(row!=m[tolower(a[i])]){
                    add=false;
                }
            }
            
            if(add){
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};