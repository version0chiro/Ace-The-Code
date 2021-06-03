#include <bits/stdc++.h>

using namespace std;

int t[1001][1001]; //depends on the constrains given;

int solve(vector<int> nums, int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    if (t[i][j] != -1)
        return t[i][j];

    int minAns = INT_MAX;

    for (int k = i; k < j; k++)
    {
        minAns = min(minAns, solve(nums, i, k) + solve(nums, k + 1, j) + nums[i - 1] * nums[k] * nums[j]);
    }

    return t[i][j] = minAns;
}

int main()
{

    memset(t, -1, sizeof(t));
    vector<int> arr={1,2,3,4};
    int n = arr.size();
    cout << solve(arr, 1, n - 1);

    return 0;
}