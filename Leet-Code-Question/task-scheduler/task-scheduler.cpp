class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(auto a:tasks){
            m[a]++;
        }
        
        struct myComp {
        constexpr bool operator()(
            pair<char, int> const& a,
            pair<char, int> const& b)
            const noexcept
            {
                return a.second < b.second;
            }
        };
        priority_queue<pair<char,int>,vector<pair<char,int>>,myComp> pq;
        for(auto a:m){
            pq.push(a);
        }
        int count=0;
        int k=n;
        queue<pair<char,int>> st;
        while(pq.size() || st.size()){
            if(n<0){
                while(st.size()){
                    pq.push(st.front());
                    st.pop();

                }
                n=k;
            }
            if(pq.size()){
                auto temp = pq.top();
                cout<<pq.size()<<" "<<temp.first<<" ";
                if(temp.second>1){
                    st.push({temp.first,temp.second-1});
                }
                pq.pop();
                
            }else{
                cout<<" ideal ";
            }
            n--;
            count++;
        }
        
        
        return count;
    }
};