class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        // unordered_map<char,int> m1,m2;
        vector<int> ans;
        for(int i=0;i<min(s.size(),p.size());i++){char a=s[i];
                                    cout<<int(a)-97<<" ";
                                    m1[int(a)-97]++;}
        for(auto a:p){m2[int(a)-97]++;}
        if(m1==m2){
            ans.push_back(0);
        }
        
        for(int i=p.size();i<s.size();i++){
            m1[int(s[i-p.size()])-97]--;
            m1[int(s[i])-97]++;
            if(m1==m2){
                ans.push_back(i-p.size()+1);
            }
        }
        
        return ans;
    }
};