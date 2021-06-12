#include <bits/stdc++.h>

using namespace std;

int main(){
    int i=0;
    int j;
    cin>>j;
    
    j=(j<<1) + (j>>1) + j;
    cout<<j;
    return 0;
}