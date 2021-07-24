class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> h;
        for(int i=0;i<arr.size();i++){
            auto a=arr[i];
            h[a]=i+1;
        }
        
        for(int i=0;i<arr.size();i++){
            auto a=arr[i];
            if(h[a*2]!=i+1 && h[a*2]!=0){
                return true;
            }
        }
    return false;
    }
};