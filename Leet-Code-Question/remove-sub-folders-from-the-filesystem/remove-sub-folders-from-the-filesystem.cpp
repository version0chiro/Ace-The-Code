class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end(), []
    (const std::string& first, const std::string& second){
        return first.size() < second.size();
    });
        string temp="";
        unordered_map<string,bool> m;
        vector<string> ans;
        for(auto a:folder){
            temp="";
            int i=0;
            for(i=0;i<a.size();i++){
                
                if((a[i]=='/') && m.find(temp)!=m.end()){
                    cout<<temp<<" "<<i<<" "<<a.size()<<" "<<a;
                    break;
                }
                temp+=a[i];
            }
            
            if(i==a.size()){
                m[temp]=true;
                ans.push_back(temp);
            }
        }
        
        
        
        return ans;
    }
};