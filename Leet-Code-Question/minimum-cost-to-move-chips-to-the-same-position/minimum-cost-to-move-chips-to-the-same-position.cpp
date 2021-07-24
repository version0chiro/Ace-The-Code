class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int ar[2]={0,0};
        for(auto a:position) {
            ++ar[a&1];
        }
        return min(ar[0],ar[1]);
    }
};