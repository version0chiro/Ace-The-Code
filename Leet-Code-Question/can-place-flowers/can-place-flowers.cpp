class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        for(int i=0;i<flowerbed.size();i++){
            cout<<flowerbed[i]<<" ";
            if( flowerbed[i]==0) {
                if((i==0 || flowerbed[i-1]!=1) && (i==flowerbed.size()-1 || flowerbed[i+1]!=1)  ){
                    count++;
                    flowerbed[i]=1;
                    cout<<" hua ";
                    
                }

            }
        }
        
        return count>=n;
    }
};