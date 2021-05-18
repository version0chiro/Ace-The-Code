#include <bits/stdc++.h>

using namespace std;


void solve(int a[],int n,int b[],int m){
    sort(a,a+n);
    sort(b,b+n);

    int sum = 0;

    for(int i=0;i<n;i++){
        sum = sum + abs(a[i]-b[i]);
    }

    cout<<sum<<endl;

}

int main(){
    int a[] = {4,1,8,7};

    int b[] = {2,3,6,5};

    int n = sizeof(a) / sizeof(a[0]);

    int m = sizeof(b) / sizeof(b[0]);

    solve(a,n,b,m);

    return 0;
}