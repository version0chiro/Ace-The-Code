// { Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


//Complete this function
bool subArrayExists(int arr[], int n)
{   set<int> sums;
    int sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){return true;}
        sum=sum+arr[i];
        // cout<<sum<<" ";
        if(sum==0){
            return true;
        }
        if(sums.find(sum)==sums.end()){
            sums.insert(sum);
        }
        else{
            return true;
        }
        
    }
    //Your code here
    return false;
}


