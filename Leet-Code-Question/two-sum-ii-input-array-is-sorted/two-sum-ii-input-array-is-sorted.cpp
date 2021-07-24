class Solution {
public:
    int binarySearch(vector<int>& numbers,int target){
        
        int lP=0,rP=numbers.size()-1;
        
        int mid;
        while(lP<rP){
             mid = lP +  (rP-lP)/2;
            
            if(numbers[mid]<target){
                lP=mid+1;
            }else{
                rP=mid;
            }
        }
        
        // cout<<mid<<" "<<lP<<" "<<rP<<" ";
        // cout<<numbers[mid]<<" "<<numbers[lP]<<" "<<numbers[rP]<<" ";
        return mid;
        
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int rPointer = numbers.size()-1;//binarySearch(numbers,target);
        int lPointer = 0;
        
        
        while(lPointer<rPointer){
            cout<<numbers[lPointer]<<" "<<numbers[rPointer]<<" "<<numbers[lPointer]+numbers[rPointer]<<" "<<"\n";
            if(numbers[lPointer]+numbers[rPointer]==target){
                return {lPointer+1,rPointer+1};
            }
            if(target<numbers[rPointer]){
                rPointer--;
            }
            else if(target>numbers[rPointer]+numbers[lPointer]){
                lPointer++;
            }
            else if(target<numbers[rPointer]+numbers[lPointer]){
                rPointer--;
            }
        }
        
        
        return {0};
    }
};