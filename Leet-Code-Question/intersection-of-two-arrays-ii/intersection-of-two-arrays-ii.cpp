class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
       int l1=nums1.size(),l2=nums2.size();
       
        vector<int> shorter, longer;
        if(l1<l2){
            shorter = nums1;
            longer = nums2;
        }else{
            longer=nums1;
            shorter = nums2;
        }
        
        vector<int> vec;
        
        unordered_map<int,int> m;
        
        for(auto a:shorter){
            m[a]++;
        }
        
        for(auto a:longer){
            if(m.find(a)!=m.end() && m[a]>0){
                m[a]--;
                vec.push_back(a);
                
            }
        }
        
        
        return vec;
        
    }
};