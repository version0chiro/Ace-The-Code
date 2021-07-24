class Solution {
public:
    double average(vector<int>& salary) {
        double maxV=INT_MIN,minV=INT_MAX;
        double sum = 0;
        
        for(auto a:salary){
            sum+=a;
            if(maxV<a) maxV=a;
            if(minV>a) minV=a;
        }
        
        // cout<<sum-maxV-minV;
        return (sum-maxV-minV)/(salary.size()-2);
        
        
    }
};