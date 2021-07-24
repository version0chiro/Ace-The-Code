class Solution {
public:
    void merge(vector<int> &nums,int left,int mid, int right){
        int subArr1=mid-left+1;
        int subArr2=right-mid;
        
        vector<int> leftA(subArr1);
        vector<int> rightA(subArr2);
        
        for(int i=0;i<subArr1;i++)
            leftA[i]=nums[i+left];
        for(int j=0;j<subArr2;j++)
            rightA[j]=nums[mid+1+j];
            
        int i1=0,i2=0,midIndex=left;
        
        
        while(i1<subArr1 && i2<subArr2){
            if(leftA[i1]<=rightA[i2]){
                nums[midIndex]=leftA[i1];
                i1++;
            }else{
                nums[midIndex]=rightA[i2];
                i2++;
            }
            
            midIndex++;
        }
        
        while(i1<subArr1){
            nums[midIndex]=leftA[i1];
            midIndex++;
            i1++;
        }
        
        while(i2<subArr2){
            nums[midIndex]=rightA[i2];
            midIndex++;
            i2++;
        }
    }
    void mergeSort(vector<int> &nums,int const begin,int const end){
        if(begin>=end)
            return;
        
        auto mid = begin+(end-begin)/2;
        
        mergeSort(nums,begin,mid);
        mergeSort(nums,mid+1,end);
        merge(nums,begin,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};