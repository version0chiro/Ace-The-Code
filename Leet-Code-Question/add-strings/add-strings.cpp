class Solution {
public:
    string addStrings(string num1, string num2) {
        int sum=0,carry=0;
        
        int n=num1.size(),m=num2.size();
        
        int p1=n-1,p2=m-1;
        
        
        string ans="";
        
        while(p1>=0 && p2>=0){
            sum = (num1[p1]-'0')+(num2[p2]-'0') + carry;
            ans+= (sum%10+'0');
            carry = sum/10;
            p1--,p2--;
        }
        
        while(p1>=0){
            sum=(num1[p1]-'0') +carry;
            ans+=(sum%10+'0');
            carry = sum/10;
            p1--;
        }
        
        while(p2>=0){
            sum=(num2[p2]-'0') +carry;
            ans+=(sum%10+'0');
            carry = sum/10;
            p2--;
        }
        
        if(carry>0){
            ans+=(carry+'0');
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};