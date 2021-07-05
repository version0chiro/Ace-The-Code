#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> arr = {13, 5, 14, 12, 8, 30, 15};
    int n = arr.size();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (arr[i] > arr[i + 1])
                sum += arr[i];
        }
        else if (i == n - 1)
        {
            if (arr[i] > arr[i - 1])
                sum += arr[i];
        }
        else
        {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
                sum += arr[i];
        }
    }

    cout << sum;
    return 0;
}