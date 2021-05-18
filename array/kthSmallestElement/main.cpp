#include <bits/stdc++.h>

using namespace std;

int main(){

    int arr[] = {7 ,10 ,4 ,3, 20 ,15};
    int n = 6;
    int k =3;

    sort(arr, arr + n, greater<int>());
    // sort(arr.begin(), arr.end());

    cout<<arr[k];



    return 0;
}