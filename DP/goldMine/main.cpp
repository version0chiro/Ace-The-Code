#include <bits/stdc++.h>

using namespace std;

int t[1001][1001];

int solve(vector<vector<int>> arr, int m, int n, int i, int j)
{
    if (i >= m || j >= m || i < 0 || j < 0)
    {
        return 0;
    }

    if (t[i][j] != -1)
    {
        return t[i][j];
    }

    return t[i][j] = arr[i][j] + max(solve(arr, m, n, i + 1, j + 1), max(solve(arr, m, n, i, j + 1), solve(arr, m, n, i - 1, j + 1)));
}

int main()
{
    vector<vector<int>> mat = {{10, 33, 13, 15},
                               {22, 21, 04, 1},
                               {5, 0, 2, 3},
                               {0, 6, 14, 2}};

    memset(t, -1, sizeof(t));

    int maxVal = INT_MIN;
    for (int i = 0; i < mat.size(); i++)
    {
        maxVal = max(maxVal, solve(mat, mat.size(), mat[0].size(), i, 0));
    }

    cout << maxVal;
    return 0;
}