class Solution {
public:
    void helper(string &s,int start,int end){
        while(start<=end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseStr(string s, int k) {
        // string sp = "abc";
        int i=0;
        int n=s.length();
        while(i<n){
            if(n-i>=2*k){
                helper(s,i,i+k-1);
                i+=2*k;
            }
            else if(n-i<2*k && n-i>k){
                helper(s,i,i+k-1);
                break;
            }
            else{
                helper(s,i,n-1);
                break;
            }
        }
        
        return s;
    }
};