class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int endTime=timeSeries[0]+duration;
        int count=duration;
        for(int i=1;i<timeSeries.size();i++){
            count+=min(timeSeries[i]-timeSeries[i-1],duration);
            // if(timeSeries[i]>endTime){
            //     count+=duration;
            // }else{
            //     count+=timeSeries[i]-timeSeries[i-1];
            // }
        }
        
        return count;
    }
};