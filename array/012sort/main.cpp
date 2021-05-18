#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {0 ,1 ,0};
    int  n =5;
    int count0=0,count1=0,count2=0;

    for(auto a:arr){
        switch(a){
            case 0:{
                count0++;
                break;
            }
            case 1:{
                count1++;
                break;
            }
            case 2:{
                count2++;
                break;
            }

        }
    }
    int i=0;
        while(count0>0){
            arr[i++]=0;
            count0--;
        }
        while(count1>0){
            arr[i++]=1;
            count1--;
        }
        while(count2>0){
            arr[i++]=2;
            count2--;
        }


        for(auto a:arr){
            cout<<a<<endl;
        }
    return 0;
}