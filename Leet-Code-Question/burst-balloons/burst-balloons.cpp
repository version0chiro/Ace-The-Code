class Solution {
public:
    int t[600][600];
    int solve(vector<int>& nums,int i,int j){
        if(i==j){
            return 0;
        }
        if(t[i][j]!=-1) return t[i][j];
        
        int minAns=INT_MIN;
        int tempAns=0;
        for(int k=i;k<j;k++){
            tempAns=solve(nums,i,k)+solve(nums,k+1,j) + nums[i-1]*nums[k]*nums[j];
            
            minAns=max(minAns,tempAns);
        }

        
        return t[i][j]=minAns;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin()+0,1);
        nums.push_back(1);
        memset(t,-1,sizeof(t));
        
        return solve(nums,1,nums.size()-1);
    }
};