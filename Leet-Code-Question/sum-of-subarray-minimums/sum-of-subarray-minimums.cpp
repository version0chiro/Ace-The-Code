class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        stack<pair<int,int>> in_stk_p,in_stk_n;
        
        vector<int> left(A.size()), right(A.size());
        
        for(int i=0;i<A.size();i++) left[i]=i+1;
        for(int i=0;i<A.size();i++) right[i]=A.size()-i;
        
        for(int i=0;i<A.size();i++){
            while(!in_stk_p.empty() && in_stk_p.top().first>A[i]) in_stk_p.pop();
            
            left[i]=in_stk_p.empty()?i+1:i-in_stk_p.top().second;
            in_stk_p.push({A[i],i});
        
            
            while(!in_stk_n.empty() && in_stk_n.top().first>A[i]){
                auto x = in_stk_n.top();in_stk_n.pop();
                right[x.second] = i - x.second;
            }
            in_stk_n.push({A[i],i});
        
        }
        
        int ans = 0, mod = 1e9 +7;
        for(int i = 0; i < A.size(); i++){
            ans = (ans + (long long)A[i]*left[i]*right[i])%mod;
         }
        
        return ans;
        
    }
};