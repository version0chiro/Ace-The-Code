class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> num2;
        while(k>0){
            num2.push_back(k%10);
            k=k/10;
        }
        
        int n=num.size(),m=num2.size();
        
        int p1=n-1,p2=0;
        
        int sum=0,carry=0;
        
        vector<int> res;
        
        while(p1>=0 && p2<m){
            sum=num[p1]+num2[p2]+carry;
            res.push_back(sum%10);
            carry=sum/10;
            p1--,p2++;
        }
        
        while(p1>=0){
            sum=num[p1]+carry;
            res.push_back(sum%10);
            carry=sum/10;
            p1--;
        }
        
        while(p2<m){
            sum=num2[p2]+carry;
            res.push_back(sum%10);
            carry=sum/10;
            p2++;
        }
        
        if(carry>0){
            res.push_back(carry);
        }
        reverse(res.begin(),res.end());
        return res;
        
        
        
    }
};