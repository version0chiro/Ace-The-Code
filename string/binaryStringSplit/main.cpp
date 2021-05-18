#include <bits/stdc++.h>

using namespace std;

int check_string(string str){
    int ctn=0;
    int ctn1=0,ctn0=0;

    for(auto a:str){
        if(a=='0'){
            ctn0++;
        }
        else if(a=='1'){
            ctn1++;
        }

        if(ctn0==ctn1){
            ctn++;
        }
    }

    if(ctn0!=ctn1){
        return -1;
    }
    return ctn;
}

int main(){
    string str;
    cin>>str;
    cout<<endl<<check_string(str);

    return 0;
}