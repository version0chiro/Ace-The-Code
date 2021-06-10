Approch:
//Sort the given meets with the start times of the pairs.
// Now make a new array to hold the ans and push the first interval inside, 
//loop through the array from 1. If the interval at value i has start time greater than end time of the last element you inserted, insert 
// the interval inside the answer vector, else , take the max of the  ending time of the lastt interval added vs end time of the interval at i and place it inside the last element in the answer vector's end time. return ans vector

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }
        }

        return ans;
    }
};