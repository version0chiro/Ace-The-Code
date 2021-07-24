class Solution {
public:
    string minWindow(string s, string t) {
        
        int n1=s.length();
        int n2=t.length();
        
        int s1[256] = {0};
        int s2[256] = {0};
        
        for(auto p:t){
            s2[p]++;
        }
        
        
        int count=0;
        int start =0 ,min_len=INT_MAX,start_index=-1;
        for(int j=0;j<n1;j++){
            
            s1[s[j]]++;
            
            if(s1[s[j]]<=s2[s[j]]){
                count++;
            }
            
            if(count==n2){
                while(s1[s[start]]>s2[s[start]]){
                    if(s1[s[start]]>s2[s[start]]){
                        s1[s[start]]--;
                    }
                    start++;
                }
                
                int temp_length= j-start+1;
                if(temp_length<=min_len){
                    start_index=start;
                    min_len=temp_length;
                }
            }
            
            
            
        }
        if(start_index==-1){
            return "";
        }
        
         else{
         return s.substr(start_index,min_len);
         }
    }
};