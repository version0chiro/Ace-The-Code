class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1,q2;
        
        for(int i=0;i<senate.size();i++){
            auto a=senate[i];
            if(a=='D')q1.push(i);
            else q2.push(i);
        }
        
        while(!q1.empty() && !q2.empty()){
            int r=q2.front(),d=q1.front();
            q1.pop(),q2.pop();
            if(r<d) q2.push(r+senate.size());
            else q1.push(d+senate.size());
        }
        
        return (q1.size()>q2.size())?"Dire":"Radiant";
    }
};