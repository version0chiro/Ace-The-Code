#include <bits/stdc++.h>

using namespace std;

void findProfit(int arr[],int n){
    int buy1=INT_MAX;
    int buy2=INT_MAX;
    int profit1=0;
    int profit2=0;
    for(int i=0;i<n;i++){
        buy1=min(buy1,arr[i]);
        profit1=max(profit1,arr[i]-buy1);
        buy2=min(buy2,arr[i]-profit1);
        profit2=max(profit2,arr[i]-buy2);
    }

    cout<<profit2;
}


int main(){ 
    int n;
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    findProfit(arr,n);


    return 0;
}