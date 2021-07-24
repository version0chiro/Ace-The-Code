class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> m;
        
        for(auto a:s){
            m[a]++;
        }
        
        stack<char> st;
        
        unordered_map<char,bool> vis;
        
        for(auto a:s){
            
            m[a]--;
            if(vis[a]==true){
                continue;
            }
            while(!st.empty() && st.top()>a && m[st.top()]>0){
                vis[st.top()]=false;
                st.pop();
                
            }
            st.push(a);
            vis[a]=true;
        }
        
        string ans="";
        
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};