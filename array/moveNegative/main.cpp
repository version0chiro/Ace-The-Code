#include <bits/stdc++.h>

using namespace std;

int main(){

    int arr[] = {-12,11,-13,-5,6,-7,5,-3,-6};
    stack<int> negativeNumbers;
    stack<int> positiveNumbers;

    for(auto a:arr){
        if(a<0){
            negativeNumbers.push(a);
        }
        else{
            positiveNumbers.push(a);
        }
    }
    int i=0;
    while(negativeNumbers.size()>0){
        arr[i++]=negativeNumbers.top();
        negativeNumbers.pop();
    }
    
    while(positiveNumbers.size()>0){
        arr[i++]=positiveNumbers.top();
        positiveNumbers.pop();
    }

    for(auto a:arr){
        cout<<a<<endl;
    }


    return 0;
}