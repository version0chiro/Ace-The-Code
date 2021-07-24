class Solution {
public:
    string simplifyPath(string path) {
        stack<string> files;
        // files.push("");
        string temp="";
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                // cout<<temp<<" ";
                // if(temp=="."){
                //     continue;
                // }
                if(temp==".."){
                    if(files.size())
                        files.pop();
                }
                else if(temp!="" && temp!=".")
                    files.push(temp);
                temp="";
            }else{
                temp+=path[i];
            }
        }
        
        
        if(temp==".."){
            if(files.size())
                    files.pop();
            }
        else if(temp!="" && temp!=".")
            files.push(temp);
        
        string ans="";
        while(files.size()){
            // ans+='/';
            ans="/"+files.top()+ans;
            files.pop();
        }
        
        if(ans=="") return "/";
        return ans;
    }
};