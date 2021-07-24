class Solution {
public:
    int maxProduct(vector<int>& A) {
        int n = A.size(),res=A[0],l=0,r=0,t=-1;
        // t?cout<<"true":cout<<"false";
        for(int i=0;i<n;i++){
            l=(l?l:1)*A[i];
            r=(r?r:1)*A[n-1-i];
            // co
            cout<<l<<" "<<r<<"\n";
            res=max(res,max(l,r));
        }
        
        return res;
    }
};