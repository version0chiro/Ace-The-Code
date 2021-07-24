class Solution {
public:
    void helper(string &s,int start,int end){
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int start=0;
        int end=0;
        for( int i=0;i<s.length();i++){
            
            if(s[i]==' '){
                helper(s,start,end-1);
                start=i+1;
                end=start;
            }else{
                end++;
            }
        }
        // cout<<start<<" "<<s[start]<<" "<<s[end-1]<<" "<<end-1;
        helper(s,start,end-1);
        return s;
    }
};