class Solution {
public: 
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumAlice=0;
        int sumBob=0;
        
        unordered_map<int,int> m;
        
        for(auto a:aliceSizes){
            m[a]++;
            sumAlice+=a;
        }
        
        for(auto a:bobSizes){
            sumBob+=a;
        }
        
        int totalSum = sumAlice+sumBob;
                
        
        // cout<<totalSum/2<<"\n";
            
        for(auto a:bobSizes){
            // cout<<a<<"\n";
            int key = totalSum/2-(sumBob-a);
            if(m.find(key)!=m.end()){
                return {key,a};
            }
            // cout<<totalSum/2-(sumBob-a)<<"\n";
            // if(m.find((totalSum/2)-(sumBob-a))!=m.end()){
            //     cout<<a<<" "<<totalSum/2 - ((totalSum/2)-(sumBob-a))<<"\n";
            // }
        }
        
        return {0,0};
    }
};