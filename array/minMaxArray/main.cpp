#include <bits/stdc++.h>

using namespace std;

int main(){
    int minElement=11,maxElement=11;
    int arr[] = {11, 21, 3,10, 14, 5, 16};
    int arrsize = sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<arrsize;i++){
        minElement = min(arr[i],minElement);
        maxElement = max(arr[i],maxElement);
    }

    cout<<minElement<<" "<<maxElement<<endl;
        
    return 0;
}