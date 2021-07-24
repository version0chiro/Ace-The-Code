class Solution {
public:
    string reorganizeString(string S) {
        string res="";
        unordered_map<char,int> hashMap;
        for(auto p:S){
            hashMap[p]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto p:hashMap){
            pq.push(make_pair(p.second,p.first));
        }
        
        while(pq.size()>1){
            auto top = pq.top();
            pq.pop();
            auto next = pq.top();
            pq.pop();
            
            res+=top.second;
            res+=next.second;
            
            top = make_pair(top.first-1,top.second);
            next = make_pair(next.first-1,next.second);
            
            if(top.first>0){
                pq.push(top);
            }
            if(next.first>0){
                pq.push(next);
            }
        }
        
        if(!pq.empty()){
            auto last = pq.top();
            if(last.first>1){
                return "";
            }
            res+=last.second;
        }
        
        return res;
    }
};