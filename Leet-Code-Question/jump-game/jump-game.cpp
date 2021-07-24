class Solution {
public:
    bool canJump(vector<int>& arr) {
        if(arr.size()==1){
            return true;
        }
        int n = arr.size();
        
        int remaingJumps=arr[0];
        int jumpsTaken=1;
        int maxJumpSoFar=INT_MIN;
        
        int iterationIndex=0;
        int diffFromMax=0;
        if(remaingJumps<1){
            return false;
        }
        while(iterationIndex<n-1){
            // cout<<arr[iterationIndex]<<" ";
            if(remaingJumps>0){
                iterationIndex++;
                remaingJumps--;
            }else if(remaingJumps==0){
                // cout<<"jumps over: new jump "<<maxJumpSoFar<<"\n";
                jumpsTaken++;
                if(iterationIndex>=maxJumpSoFar){
                    return false;
                }
                remaingJumps=maxJumpSoFar-iterationIndex;
            }
            
            maxJumpSoFar=max(maxJumpSoFar,arr[iterationIndex]+iterationIndex);
        }
        // cout<<"\n";
        return true;
    }
};