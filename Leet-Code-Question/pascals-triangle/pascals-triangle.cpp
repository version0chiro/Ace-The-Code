class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> start;
        start.push_back(1);
        vector<vector<int>> ans;
        ans.push_back(start);
        if(numRows==1){
            return ans;
        }
        for(int i=1;i<numRows;i++){
            vector<int> arr (i+1);
            arr[0]=1;
            arr[i]=1;
            for(int j=1;j<i;j++){
                arr[j]=ans.back()[j]+ans.back()[j-1];
            }
            ans.push_back(arr);
        }
        return ans;
    }
};