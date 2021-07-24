class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool comment=false;
        string s;
        for(auto a:source){
            for(int j=0;j<a.size();j++){
                if(!comment && j+1<a.size() && a[j]=='/' && a[j+1]=='/') break;
                else if(!comment && j+1<a.size() && a[j]=='/' && a[j+1]=='*') comment=true,j++;
                else if(comment && j+1<a.size() && a[j]=='*' && a[j+1]=='/') comment=false,j++;
                else if(!comment) s.push_back(a[j]);
            }
            
            if(!comment && s.size()) ans.push_back(s),s.clear();
        }
        
        return ans;
    }
};