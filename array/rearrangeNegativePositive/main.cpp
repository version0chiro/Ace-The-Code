#include <bits/stdc++.h>

using namespace std;

void rearrangeNegativePositive(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            j++;
            swap(arr[i],arr[j]);
        }
    }

    int negPointer=0,posPointer=j+1;
    while(negPointer<posPointer && posPointer<n && arr[negPointer]<0){
        swap(arr[negPointer],arr[posPointer]);
        posPointer++;
        negPointer=negPointer+2;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}

int main(){
    int n;
    cin>>n;
    int arr[n] ;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    rearrangeNegativePositive(arr,n);

    return 0;
}