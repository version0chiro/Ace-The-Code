class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> s;
        int j=0;
        vector<string> ans;
        for(int i=0;i<n && j<target.size();i++){
            if(i+1==target[j]){
                s.push(i+1);
                j++;
                ans.push_back("Push");
            }else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        
        
        return ans;
    }
};