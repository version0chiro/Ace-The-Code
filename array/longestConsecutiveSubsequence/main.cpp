// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long  minSoFar=1;
	    long long  maxSoFar=1;
	    
	    long long one=1;
	    
	    long long finalProd=0;
	    bool flag=0;
	    
	    
	    for(int i=0;i<n;i++){
	        if(arr[i]>0){
	            maxSoFar = maxSoFar*arr[i];
	            minSoFar = min(minSoFar*arr[i],one);
	            flag=1;
	            
	        }
	        else if (arr[i]==0){
	            maxSoFar=one;
	            minSoFar=one;
	        }
	        else{
	            long long temp = maxSoFar;
	            maxSoFar=max(minSoFar*arr[i],one);
	            minSoFar = temp*arr[i];
	        }
	        
	        if(maxSoFar>finalProd){
	            finalProd = maxSoFar;
	        }
	        
	        
	    }
	    
	    if(flag==0 && finalProd ==0){
	        return 0;
	    }
	    
	    return finalProd;
	    
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends