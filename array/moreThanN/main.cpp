#include <bits/stdc++.h>

using namespace std;

void moreThanN(int arr[],int n,int k){
    unordered_map<int,int> m;
    vector<int> ans;
    int conditionNumber= n/k;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    for(auto a:m){
        if(a.second>conditionNumber){
            ans.push_back(a.first);
        }
    }


    for(auto a:ans){cout<<a;}
}

int main(){
    int n,k;
    cin>>n>>k;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    moreThanN(arr,n,k);



    return 0;
}