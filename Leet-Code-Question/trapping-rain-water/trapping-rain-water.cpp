class Solution {
public:
    int trap(vector<int>& arr) {
    int n = arr.size();
    int leftPointer=0;
    int rightPointer=n-1;
    
    int leftWall = 0;
    int rightWall=0;
    
    int total =0;
    
    while(leftPointer<=rightPointer){
        if(rightWall<=leftWall){
            // cout<<"-->"<<arr[rightPointer];
            total = total + max(0,rightWall-arr[rightPointer]);
            
            rightWall = max(arr[rightPointer],rightWall);
            
            rightPointer--;
        }
        else{
            // cout<<"-->"<<arr[leftPointer];
            total = total + max(0,leftWall - arr[leftPointer]);
            
            leftWall = max(arr[leftPointer],leftWall);
            
            
            leftPointer++;
        }
    }
    
    return total;
    }
};