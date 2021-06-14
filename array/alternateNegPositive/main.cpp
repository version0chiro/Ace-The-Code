#include <bits/stdc++.h>

using namespace std;

void altNegPos(vector<int> &arr, int n, int posCount, int negCount)
{
    int j = 0, i = 0;
    while (i < n && posCount > 0 && negCount > 0)
    {

        if (i % 2 == 1 && arr[i] >= 0)
        {
            i++;
            posCount--;
        }
        else if (i % 2 == 0 && arr[i] < 0)
        {
            i++;
            negCount--;
        }
        else if (i % 2 == 0 && arr[i] >= 0)
        {
            cout << "\n " << i % 2 << " " << i << " going in 1nd for " << arr[i] << " ";
            j = i;
            while (j < n && arr[i] >= 0)
            {
                swap(arr[i], arr[j]);
                cout << "swapping " << arr[i] << " " << arr[j] << "\n";
                j++;
            }
            i++;
            negCount--;
        }
        else
        {
            cout << "\n"
                 << i << " going in 2nd for " << arr[i] << " ";
            j = i;
            while (j < n && arr[i] < 0)
            {
                swap(arr[i], arr[j]);
                cout << "swapping " << arr[i] << " " << arr[j] << "\n";
                j++;
            }
            i++;
            posCount--;
        }
    }
}

int main()
{

    int n;
    cin >> n;
    int negCount = 0;
    int posCount = 0;
    vector<int> arr;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp >= 0)
            posCount++;
        else
            negCount++;
        arr.push_back(temp);
    }

    altNegPos(arr, n, posCount, negCount);

    cout << "\n ";
    for (auto a : arr)
    {
        cout << a << " ";
    }
    return 0;
}