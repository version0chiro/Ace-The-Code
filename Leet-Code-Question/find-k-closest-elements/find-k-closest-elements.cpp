class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pi> pq;
        
        for(auto a:arr){
            pq.push({abs(a-x),a});
            
            if(pq.size()>k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(pq.size()){
            ans.push_back(pq.top().second);
            // cout<<pq.top().first<<" "<<pq.top().second<<"\n";
            pq.pop();
        }
        
        sort(ans.begin(),ans.end());
    
        return ans;
    }
};