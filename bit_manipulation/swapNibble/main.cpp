// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int swapNibbles(unsigned char x){
        // code here
        bitset<8> bset1(x);
        
        bitset<4> nibble1,nibble2;
        
        for(int i=0;i<4;i++){
            nibble2[i]=bset1[i];
        }
        
        for(int j=4;j<8;j++){
            nibble1[j-4]=bset1[j];
        }
        
        // cout<<nibble1<<" "<<nibble2<<" \n";
        
        int j=0;
        for(int i=0;i<4;i++){
            bset1[j]=nibble1[i];
            j++;
        }
        
        for(int i=0;i<4;i++){
            bset1[j]=nibble2[i];
            j++;
        }
        
        // for(int i=0;i<8;i++){
            
        // }
        return (int)bset1.to_ulong();
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.swapNibbles(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends