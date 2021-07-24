class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        priority_queue<int,vector<int>,greater<int>> nQ(A.begin(),A.end());
        
        while(!nQ.empty() && K-->0 ){
            int curr = nQ.top();
            nQ.pop();
            if(curr>=0){
                K%=2;
            }
            nQ.push(-1*curr);
        }
        int sum=0;
        for(;!nQ.empty();nQ.pop()){
            sum+=nQ.top();   
        }
        
        return sum;
    }
};