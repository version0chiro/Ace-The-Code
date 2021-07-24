class Solution {
public:
    bool static cmp(pair<int,int> a,pair<int,int> b){
        if(a.first>b.first){
            return true;
        }else{
            return false;
        }
    }
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        vector<pair<int,int>> v;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<labels.size();i++){
            m[labels[i]]=use_limit;
            v.push_back({values[i],labels[i]});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        int sum=0;
        
        for(auto a:v){
            if(num_wanted==0){
                break;
            }
            if(m[a.second]>0){
                num_wanted--;
                sum+=a.first;
                m[a.second]--;
            }
            // cout<<a.first<<" "<<a.second<<"\n";
        }
        
        return sum;
    }
};