
#include <bits/stdc++.h>

using namespace std;

int *SpiralTraverse(int **arr, int m, int n)
{
    int left = 0, right = m - 1, bottom = n - 1, top = 0;

    int direction = 1;

    int *x = new int[m * n];
    int it = 0;

    while (left <= right && top <= bottom)
    {
        if (direction == 1)
        {
            for (int i = left; i <= right; i++)
            {
                x[it] = (arr[top][i]);
                it++;
            }

            direction = 2;
            top++;
        }

        else if (direction == 2)
        {
            for (int i = top; i <= bottom; i++)
            {
                x[it] = arr[i][right];
                it++;
            }
            direction = 3;
            right--;
        }

        else if (direction == 3)
        {
            for (int i = right; i >= left; i--)
            {
                x[it] = arr[bottom][i];
                it++;
            }
            direction = 4;
            bottom--;
        }

        else if (direction == 4)
        {
            for (int i = bottom; i >= top; i--)
            {
                x[it] = (arr[i][left]);
                it++;
            }

            direction = 1;
            left++;
        }
    }

    return x;
}

int main()
{
    int n = 4, m = 4;

    int **X = new int *[n];
    for (int i = 0; i < n; i++)
    {
        X[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            X[i][j] = temp;
        }
    }

    int *result = SpiralTraverse(X, m, n);

    for(int i = 0; i < n*m; i++){
        cout <<result[i] << " ";
    }

    return 0;
}
