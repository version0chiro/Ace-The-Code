class Solution {
public:
    int countBit(int n){
        int count=0;
        while(n>0){
            if(n%2==1) count++;
            n=n/2;
        }
        
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        map<int,vector<int>> m;
        for(auto a:arr){
            m[countBit(a)].push_back(a);
        }
        
        vector<int> ans;
        
        for(auto a:m){
            for(auto p:a.second){
                ans.push_back(p);
            }
        }
        
        return ans;
    }
};