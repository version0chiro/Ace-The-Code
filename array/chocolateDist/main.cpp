#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int solution(int arr[],int n,int m){
    sort(arr,arr+n);
    int difference=INT_MAX;
    int count=0;
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<"  ";
    // }
    // cout<<endl;
    while(count<n-m+1){
        // cout<<arr[count]<<"=="<<arr[count+m-1]<<endl;
        difference = min(difference,arr[count+m-1]-arr[count]);
        count++;
    }
    
    return difference;
}

int main() {
    
	//code
	int n;
	int m;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	cin>>m;
	cout<<solution(arr,n,m);
	
	return 0;
}