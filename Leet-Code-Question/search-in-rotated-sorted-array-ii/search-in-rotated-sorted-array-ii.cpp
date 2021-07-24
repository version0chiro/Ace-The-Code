class Solution {
public:
    int search_util(vector<int> arr,int target,int l,int r){
        if(l>r) return -1;
        
        int mid = (l+r)/2;
        if(arr[mid]==target)
            return mid;
        
        if((arr[l]==arr[mid]) && arr[r]==arr[mid]){
            ++l;
            --r;
            return search_util(arr,target,l,r);
        }
        
        if(arr[l]<=arr[mid]){
            if(target>=arr[l] && target<=arr[mid]){
                return search_util(arr,target,l,mid-1);
            }
            
            
            return search_util(arr,target,mid+1,r);;
        }
        
        if(target>=arr[mid] && target<=arr[r])
            return search_util(arr,target,mid+1,r);
        
        return search_util(arr,target,l,mid-1);
    }
    bool search(vector<int>& nums, int target) {
        if(search_util(nums,target,0,nums.size()-1)!=-1)
            return true;
        
        return false;
    }
};