#include <bits/stdc++.h>

using namespace std;


int main(){

    int n ;
    cin>>n;
    int 
    int x = log(n)/log(2);

    int i;

    // cout<<x;

    int binArr[x];

    for(i=0;n>0;i++){
        binArr[i] = n%2;
        n=n/2;
    }

    for(i=i-1 ;i>=0 ;i--)    
{    
cout<<binArr[i];    
}  
    return 0;
}