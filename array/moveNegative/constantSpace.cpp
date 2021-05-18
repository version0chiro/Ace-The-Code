#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {-12,11,-13,-5,6,-7,5,-3,-6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int leftPointer=0;
    int rightPointer=n-1;
    while(leftPointer < rightPointer){
        if(arr[leftPointer]<0 && arr[rightPointer]<0){
            leftPointer++;
        }

        else if(arr[leftPointer]>0 && arr[rightPointer]<0){
            swap(arr[leftPointer],arr[rightPointer]);
            leftPointer++;
            rightPointer--;
        }

        else if(arr[leftPointer]>0 && arr[rightPointer]>0){
            rightPointer--;
        }
        else{
            leftPointer++;
            rightPointer--;
        }

    }

    for(auto a:arr){
        cout<<a<<endl;
    }

    
}