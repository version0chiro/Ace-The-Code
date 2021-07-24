class Solution {
public:
    typedef pair<int, int> PAIR;

    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        vector<int> ans;
        map<int,int> m;
        for(auto a:barcodes){
            m[a]++;
        }
        
        struct cmp {
        bool operator()(const PAIR &a, const PAIR &b) {
            return a.second < b.second;
        };
         };
        priority_queue<PAIR,vector<PAIR>,cmp> pq(m.begin(),m.end());
        
        while(!pq.empty()){
            
            auto temp=pq.top();
            if( ans.size()==0 || (ans.size()>=1 && ans.back()!=temp.first)){
                ans.push_back(temp.first);
                pq.pop();
                if(temp.second>1)
                    pq.push({temp.first,temp.second-1});
            }else{
                pq.pop();
                if(pq.empty()) break;
                auto temp2=pq.top();
                pq.pop();
                ans.push_back(temp2.first);
                if(temp2.second-1>0){
                    pq.push({temp2.first,temp2.second-1});
                }
                pq.push(temp);
            }
           
        }
        
        
        
        
        
        return ans;
    }
};