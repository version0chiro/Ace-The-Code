// approach:keep a track of the maximum reach you can go from any point in the array, this can be done with current index+value of array at index,
// take max of this element while iteration, at any point steps become 0, take the counter for steps up by one point. replace the reamaing steps varibale with
//  maxReach - currentIndex (becuase you have come ahead a bit). If the maxReach is less than or equal to the current index that means you are stuck in a 0 and it is impossible to traverse the array. 
//  Thus return -1. init the first number of steps available as arr[0] and startrr the jump counter from 1 as you have to take the first jump no matter what.



// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        int remaingJumps = arr[0];
        int jumpsTaken = 1;
        int maxJumpSoFar = INT_MIN;

        int iterationIndex = 0;
        int diffFromMax = 0;
        if (remaingJumps < 1)
        {
            return -1;
        }
        while (iterationIndex < n - 1)
        {
            // cout<<arr[iterationIndex]<<" ";
            if (remaingJumps > 0)
            {
                iterationIndex++;
                remaingJumps--;
            }
            else if (remaingJumps == 0)
            {
                // cout<<"jumps over: new jump "<<maxJumpSoFar<<"\n";
                jumpsTaken++;
                if (iterationIndex >= maxJumpSoFar)
                {
                    return -1;
                }
                remaingJumps = maxJumpSoFar - iterationIndex;
            }

            maxJumpSoFar = max(maxJumpSoFar, arr[iterationIndex] + iterationIndex);
        }
        // cout<<"\n";
        return jumpsTaken;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends