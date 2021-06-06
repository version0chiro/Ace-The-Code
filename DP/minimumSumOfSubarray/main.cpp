#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr)
{
    int minSoFar = INT_MAX;
    int temp = 0;
    for (auto a : arr)
    {
        if (temp > 0)
        {
            temp = a;
        }
        else
        {

            temp += a;
        }
        minSoFar = min(temp, minSoFar);
    }

    return minSoFar;
}

int main()
{
    vector<int> arr = {2, 6, 8, 1, 4};

    cout << solve(arr) << endl;

    return 0;
}