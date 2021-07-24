static int x=[](){ios::sync_with_stdio(false); cin.tie(NULL); return 0;}();

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int countNumberOfOnes = 0;
        for(int c:arr){
            if(c){
                countNumberOfOnes++;
            }
        }
        
        if(countNumberOfOnes==0){
            return {0,(int)arr.size()-1};
        }
        
        if(countNumberOfOnes%3!=0){
            return {-1,-1};
        }
        
        int k = countNumberOfOnes/3;
        
        int i;
        
        for(i=0;i<arr.size();i++){
            if(arr[i]) break;
        }
        
        int start =i;
        int count1= 0;
        for(i=0;i<arr.size();i++){
            if(arr[i])
                count1++;
            
            if(count1==k+1) break;
        }
        int mid = i;
        count1=0;
        
        for(i=0;i<arr.size();i++){
            if(arr[i]) count1++;
            
            if(count1==2*k+1) break;
        }
        
        int end = i;
        
        while(end<arr.size() && arr[start]==arr[mid] && arr[mid]==arr[end]){
            start++,mid++,end++;
        }
        
        
        if(end==arr.size()) return {start-1,mid};
        
        return {-1,-1};
    }
    
};