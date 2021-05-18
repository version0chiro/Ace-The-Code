#include<bits/stdc++.h>

using namespace std; 

bool isPalindrome(string s){
    int l = s.length();
    int j;
    for(int i=0,j=l-1;i<=j;i++,j--){
        if(s[i]!=s[j]){
            return false;
        }
    }return true;
}


int main(){
    string s = "AACECAAAAA";
    int cnt = 0;
    bool flag = 0;

    while(s.length()>0){
        if(isPalindrome(s)){
            flag = 1;
            break;
        }
        else{
            cnt++;
            s.erase(s.begin() +s.length()-1);
        }
    }

    if(flag){
        cout<<cnt;
    }

    return 0;
}