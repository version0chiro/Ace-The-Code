// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    int backPointer=-1;
    int frontPointer=0;
    int counter=0;
    
    while(frontPointer<n){
        if(arr[frontPointer]<=k && backPointer<0){
            backPointer=frontPointer;
            // frontPointer++;
            
            cout<<"back Set Kiya";
        }
        else if(arr[frontPointer]<=k && frontPointer==backPointer){
            frontPointer++;
            backPointer++;
            cout<<"dono agge gaye";
            
        }
        
      
        
        else if(arr[frontPointer]<=k && frontPointer>backPointer){
            swap(arr[frontPointer],arr[backPointer]);
            backPointer++;
            frontPointer++;
            counter++;
            cout<<"swap hua aur agge gaye";
            
        }
        else if(arr[frontPointer]>k){
            frontPointer++;
            cout<<"ek front agge gaya";
        }
        cout<<endl;
    }
    // Complet the function
    return counter;
}
