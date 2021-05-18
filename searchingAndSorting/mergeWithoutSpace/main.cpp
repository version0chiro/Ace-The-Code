// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    // code here
	    
	    for(int i=m-1;i>=0;i--){
	        int j,last=arr1[n-1];
	        for( j=n-2;j>=0 && arr1[j]>arr2[i];j--){
	            arr1[j+1]=arr1[j];
	        }
	        if(j!=n-2 || last > arr2[i]){
	            arr1[j+1] = arr2[i];
	            arr2[i]=last;
	        }
	    }
	}
};

// void merge(int ar1[], int ar2[], int m, int n)
// {
//     // Iterate through all elements 
//     // of ar2[] starting from the last element
//     for (int i = n - 1; i >= 0; i--) 
//     {
//         /* Find the smallest element greater than ar2[i].
//         Move all elements one position ahead till the
//         smallest greater element is not found */
//         int j, last = ar1[m - 1];
//         for (j = m - 2; j >= 0 
//              && ar1[j] > ar2[i]; j--)
//             ar1[j + 1] = ar1[j];
 
//         // If there was a greater element
//         if (j != m - 2 || last > ar2[i]) 
//         {
//             ar1[j + 1] = ar2[i];
//             ar2[i] = last;
//         }
//     }
// }
 

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends