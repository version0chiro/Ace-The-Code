#include <bits/stdc++.h>

using namespace std;

void print_subsequences(string input,string output){
    if(input.length() ==0){
        cout<<output<<" "<<endl;
        return;
    }

    print_subsequences(input.substr(1),output);
    print_subsequences(input.substr(1),output+input[0]);
}

int main(){
    string str;
    cin>>str;
    string output="";

    print_subsequences(str,output);


    return 0;
}