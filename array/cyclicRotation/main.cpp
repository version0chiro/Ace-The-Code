#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {1,2,3,4,5};
    int n = 5;//sizeof(arr)/sizeof(arr[0]);
    int temp = arr[n-1];
    for(int i=n-1; i>=0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
    cout<<endl;
    for(auto a:arr){
        cout<<a<<" "<<endl;
    }

    return 0;
}