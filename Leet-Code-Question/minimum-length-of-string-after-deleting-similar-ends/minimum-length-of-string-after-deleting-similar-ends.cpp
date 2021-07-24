class Solution {
public:
    int minimumLength(string s) {
        int l=0,r=s.size()-1;
        int count=0;
        while(l<r){
            if(s[l]==s[r]){
                cout<<s[l]<<" ";
                char temp = s[l];
                while(l<=r && s[l]==temp){
                    l++;
                }
                while(l<=r && s[r]==temp){
                    r--;
                }
            }else{
                cout<<endl<<s[l]<<" "<<s[r]<<" ";
                break;
            }
        }
        
        
        return max(r-l+1,0);
    }
};