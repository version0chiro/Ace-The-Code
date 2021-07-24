class Solution {
public:
    unordered_map<string,bool> checkMap;
    void solve(vector<string> &ans,string s,int count,string curr,int i,int n,int open,int closing){
        if(checkMap[curr]){
            return;
        }
        // cout<<curr<<" "<<i<<" "<<open<<" "<<closing<<" "<<count<<" "<<curr.length()<<"\n";
        
        if(i==count && curr.length()==n && open==closing){
        
            if(!checkMap[curr]){
                ans.push_back(curr);
                checkMap[curr]=true;
            }
            return;
        }
        if(closing>open){
            return;
        }
        
        else{
            if(s[i]=='('){
                    solve(ans,s,count,curr+'(',i+1,n,open+1,closing);
                    checkMap[curr+'(']=true;
                    solve(ans,s,count,curr,i+1,n,open,closing);
                    checkMap[curr]=true;

            }else if(s[i]==')'){
                    solve(ans,s,count,curr+')',i+1,n,open,closing+1);
                    checkMap[curr+')']=true;
                    solve(ans,s,count,curr,i+1,n,open,closing);        
                    checkMap[curr]=true;
            }else if(isalpha(s[i])){
                solve(ans,s,count,curr+s[i],i+1,n,open,closing);
                checkMap[curr+s[i]]=true;

            }
        }
        return;
        
    }
    
    vector<string> removeInvalidParentheses(string s) {
       
        vector<string> ans;
        int count=0;
        int lCount=0,rCount=0;
        for(auto p:s){
            if(p=='('){
                lCount++;
            }else if(p==')'){
                if(lCount>0){
                    lCount--;
                }else{
                    rCount++;
                }
            }
        }
        count+=lCount+rCount;
        cout<<count;

        solve(ans,s,s.length(),"",0,s.length()-count,0,0);
        // cout<<count;
        if(ans.size()<1){
            return {""};
        }
        return ans;
    }
};