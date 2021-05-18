#include <bits/stdc++.h>

using namespace std;

void solve(int arr[], int n){
    vector<int> ansV;
    int i=0;
    int j =n-1;

    sort(arr,arr+n);

    while(i<j){
        ansV.push_back(arr[i]);
        ansV.push_back(arr[j]);
        i++;
        j--;
    }

    int sum = 0;

    for(int i=1;i<n;i++){
        cout<<ansV[i]<<" "<<ansV[i-1]<<" "<<abs(ansV[i]-ansV[i-1])<<" "<<sum<<"\n";
        sum += abs(ansV[i]-ansV[i-1]);
    }

    sum+=abs(ansV[0]-ansV[n-1]);
    cout<<"\n";
    cout << sum;

}

int main(){
    int arr[] = {1,2,4,8};

    int n = sizeof(arr)/sizeof(arr[0]);

    solve(arr,n);

    return 0;
}