// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=1;
        int end=n;
        int mid;
        while(i<=end){
            mid=i+(end-i)/2;
            if(isBadVersion(mid) && !isBadVersion(mid-1)){
                return mid;
            }
            else if(isBadVersion(mid) && isBadVersion(mid-1)){
                end=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        
        return mid;
            
            
    }
};