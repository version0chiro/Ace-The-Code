class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length=0;
        queue<int> q;
        for(auto a:nums){
            if(a!=0){
                length++;
                q.push(a);
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(!q.empty()){   
            while(!q.empty()){
                nums[i]=q.front();
                q.pop();
                i++;
            }
                i=i-1;
            }else{
                nums[i]=0;
            }
        }
    }
};