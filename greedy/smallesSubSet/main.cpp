#include <bits/stdc++.h>

using namespace std;

void solve(int arr[],int n){
    sort(arr,arr+n,greater<int>());

    vector<int> ans;
    int totalSum = 0;
    int tempSum=0;

    for(int i=0;i<n;i++){
        totalSum += arr[i];
    }

    for(int i=0;i<n;i++){
        tempSum+= arr[i];
        ans.push_back(arr[i]);
        if(tempSum>totalSum/2){
            break;
        }
    }

    cout <<ans.size() << endl;

}

int main(){
    int arr[]={3,1,7,1};

    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr,n);

    return 0;
}