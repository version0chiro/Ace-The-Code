#include <bits/stdc++.h>


using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> finalAnswer;
        sort(intervals.begin(),intervals.end());
        finalAnswer.push_back(intervals.front());
        for(int i=1;i<intervals.size();i++){
            // cout<<finalAnswer.back()[0]<<"---";
            if(intervals[i][0]<=finalAnswer.back()[1]){
                finalAnswer.back()[1]=max(intervals[i][1],finalAnswer.back()[1]);
            }
            else{
                finalAnswer.push_back(intervals[i]);
            }
            // cout<<intervals[i][0]<<"==="<<endl;
        }
        return finalAnswer;
    };   
};

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        
    }

    return 0;
}