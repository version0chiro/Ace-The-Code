class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans="";
        while(i<word1.size() && j<word2.size()){
            // cout<<i<< " "<<j<<" \n";
            ans+=word1[i];
            ans+=word2[j];
            i++;
            j++;
        }
        // cout<<i<< " "<<j<<" \n";
        while(i<word1.size()){
            ans+=word1[i];
            i++;
        }
        // cout<<i<< " "<<j<<" \n";
        while(j<word2.size()){
            ans+=word2[j];
            j++;
        }
        
        // cout<<ans;
        return ans;
    }
};