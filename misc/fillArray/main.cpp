#include <bits/stdc++.h>
using namespace std;
const unsigned int M = 1000000007;

int findSolutions(int N)
{

    int count = 0;

    for (int i = 1; i <= sqrt(N); i++)
    {

        if (N % i == 0)
        {

            if ((i + N / i) % 2 == 0)
            {
                count++;
            }
        }
    }

    return count;
    // cout <<  count << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        int prod = 1;
        vector<int> arr2;
        for (auto a : arr)
        {
            prod = (prod * findSolutions(a)) % M;
            // arr2.push_back(findSolutions(a));
        }

        cout << prod << endl;
    }

    return 0;
}
