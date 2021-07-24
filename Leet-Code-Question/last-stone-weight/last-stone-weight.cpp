class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto a:stones){
            pq.push(a);
        }
        
        while(pq.size()!=1){
            int y = pq.top();
            pq.pop();
            int x= pq.top();
            pq.pop();
            if(y-x>=0){
                pq.push(y-x);
            }
        }
        
        return pq.top();
    }
};