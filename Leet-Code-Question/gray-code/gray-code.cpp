class Solution {
public:
    void solve(bitset<32>& bits,vector<int>& result,int k){
        if(k==0){
            result.push_back(bits.to_ulong());
        }else{
            solve(bits,result,k-1);
            bits.flip(k-1);
            solve(bits,result,k-1);
        }
    }
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        solve(bits,result,n);
        return result;
    }
};