#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    int count=1;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        map<int,int> m;

        sort(v.begin(),v.end());
        int p=0;
        int total=0;
        // cout<<"================================================================";
        for(auto a:v){
            
            if(m[a]==0){
                p++;
                m[a] = p;
            }

            total = total + m[a];
            // cout<<a<<" "<<m[a]<< " "<<total<<"\n";
        }

        cout<<"Case #"<<count<<": "<<total<<endl;
        count++;
        t--;
    }

    return 0;
}