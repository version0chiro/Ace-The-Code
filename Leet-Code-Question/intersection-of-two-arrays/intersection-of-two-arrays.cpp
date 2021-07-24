class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        vector<int> answer;
        for(auto a:nums1){
            m[a]=-20;
        }
        for(auto a:nums2){
            if(m[a]!=-10){
                if(m[a]!=0){
                    m[a]++;
                if(m[a]>-20){
                    m[a]=-30;
                    answer.push_back(a);
                }
                }
                    
            }

        }
        
        return answer;
    }
};