class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        vector<pair<int,int>> vec;
        for(int i=0;i<startTime.size();i++){
            vec.push_back({startTime[i],endTime[i]});
        }
        int count=0;
        for(auto a:vec){
            if(a.first<=queryTime && a.second>=queryTime) count++;
        }
        
        return count;
    }
};