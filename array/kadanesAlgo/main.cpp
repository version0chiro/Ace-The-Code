#include <bits/stdc++.h>

using namespace std;

int main(){

    int n=5;

    int arr[] = {1,2,3,-2,5};

    int max_so_far = INT_MIN,max_ending_here=0;

    for (int i=0;i<n;i++){
        max_ending_here = max_ending_here + arr[i];
        if(max_ending_here<0)
            max_ending_here = 0;
        if(max_so_far<max_ending_here){
            max_so_far = max_ending_here;
        }
    }

    cout<<max_so_far<<endl;

    return 0;
}