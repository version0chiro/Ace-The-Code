#include <bits/stdc++.h>

using namespace std;

int minJumps( int arr[],int n){
    int steps=arr[0];
    int jumps=1;
    int maxReach=arr[0];
    if(steps<1){
        return -1;
    }

    
    for(int i=1;i<n;i++){ //
    
    if(i==n-1){
        return jumps;
    }
     maxReach = max(maxReach,arr[i]+i);
    //  cout<<maxReach;
     steps=steps-1;
     if(steps==0){
         jumps++;
         steps = arr[i];
         if(i>=maxReach){
             return -1;
         }
         steps = maxReach-i;
     }
     

    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<endl<<minJumps(n,arr)<<endl;
    return 0;
}