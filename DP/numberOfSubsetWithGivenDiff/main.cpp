#include<bits/stdc++.h>

using namespace std;

int CountSubsets(vector<int> arr,int diff){
    int sum=0;
    for(auto a:arr){
        sum+=a;
    }

    int targetSum = (sum+diff)/2;

    int n = arr.size();

    int t[n + 1][targetSum + 1];

    for(int j=0;j<targetSum+1;j++){
        t[0][j] = 0;
    }

    for(int i=0;i<n+1;i++){
        t[i][0] = 1;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<targetSum+1;j++){
            if(arr[i-1]<=j){
                t[i][j] =t[i-1][j - arr[i-1]] + t[i-1][j];
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][targetSum];

}

int main(){

    vector<int> arr={1,1,2,3};
    int diff = 1;

    cout<<CountSubsets(arr,diff);

    return 0;
}