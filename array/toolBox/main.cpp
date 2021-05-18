#include <bits/stdc++.h>

using namespace std;

// Given an array of string containing names of tools (can be duplicates),
// the starting index and a target tool, find the minimum number of steps required to reach the 
// target tool from the starting index. The array is circular, that is,
// if you reach the end of the array, go to its start and vice versa.

int minDistance(string arr[], int n,string target,int start){
    int lPointer = start;
    int rPointer = start;

    int leftDistance = 0;
    int rightDistance = 0;

    while((arr[lPointer]!=target && arr[rPointer]!=target)){
        

        if(rPointer==n){
            rPointer=0;
        }
        else if(lPointer==-1){
            lPointer=n-1;
        }
        if(arr[rPointer]==target){
            break;
        }
        if(arr[lPointer]==target){
            break;
        }




        cout<<arr[lPointer]<<" "<<arr[rPointer]<<" "<<endl;
        ++leftDistance;
        ++rightDistance;
        --lPointer;
        ++rPointer;
    
    }

    cout<<arr[lPointer]<<" "<<arr[rPointer]<<" "<<endl;

    return min(leftDistance,rightDistance);
}

int main(){
    int n;
    cin>>n;
    string arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    };

    string target;
    cin>>target;

    int start;
    cin>>start;

    cout<<endl<<minDistance(arr,n,target,start)<<endl;
    
    return 0;
}