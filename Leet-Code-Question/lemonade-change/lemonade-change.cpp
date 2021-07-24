class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[3];
        arr[0]=arr[1]=arr[2]=0;
        for(int i= 0;i<bills.size();i++){
            if(bills[i]==5){
                arr[0]+=5;
            }else if(bills[i]==10){
                if(arr[0]<5){
                    return false;
                }
                arr[0]-=5;
                arr[1]+=10;
            }else if(bills[i]==20){
                if( (arr[0]<10 && (arr[0]<5 || arr[1]<10)) || arr[0]+arr[1]<15){
                    return false;
                }
                if(arr[1]<10){
                    arr[0]-=15;
                }else{
                    arr[1]-=10;
                    arr[0]-=5;
                }
            }
        }
        
        return true;
    }
};