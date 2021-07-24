class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        string prev="";
        string temp="";
        string part="";
        bool check=false;
        for(auto a:text){
            if(a==' '){
                if(check){
                    ans.push_back(temp);
                    check=false;
                } 
                // cout<<prev<<" "<<temp<<" \n";
                if(first==prev && second==temp){
                    check=true;
                }
                prev=temp;
                temp="";
            }
            else{
                temp=temp+a;
            }
        }
        if(check)
            ans.push_back(temp);
        // cout<<temp;
        
        
        return ans;
    }
};