#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=5,m=3;
    set<int> unions;
    set<int> intersections;
    int fArray[] = {1,2,3,4,5};
    int sArray[] = {1,2,3};
    int fCounter=0; int sCounter=0;
    while(fCounter<n || sCounter<m){
        if(fArray[fCounter]==sArray[sCounter]){
            intersections.insert(fArray[fCounter]);
        }
        if(fCounter<n){
            unions.insert(fArray[fCounter]);
            fCounter++;
        }
            
        if(sCounter<m){
            unions.insert(sArray[sCounter]);
            sCounter++;
        }
            
        
    }

    cout<<unions.size()<<endl;

    cout<<intersections.size();
    // for(auto a: unions){
    //     cout<<a<<endl;
    // }

    return 0;
}