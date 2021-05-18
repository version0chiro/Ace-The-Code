#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {1, 2, 3,10, 4, 5, 6};
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    int temp;
    for(auto a:arr){
        cout<< a <<" ";
    }
    cout<< endl;
    for(int i=0; i<arrsize/2;i++){
        temp = arr[i];
        arr[i] = arr[arrsize-1-i] ;
        arr[arrsize-1-i] = temp;
    }

    for(auto a:arr){
        cout<< a <<" ";
    }
    return 0;
}