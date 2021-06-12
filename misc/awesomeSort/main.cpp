#include <bits/stdc++.h>

using namespace std;

bool static cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
        return true;
    else
        return false;
}
vector<int> awesomeSort(long long n, vector<int> arr)
{
    vector<int> odd, ans, div_five;
    vector<pair<int, int>> non_div_five;

    for (long long i = 0; i < n; i++)
    {

        long long a = arr[i];
        {
            if (a % 2 == 0)
            {
                if (a % 5 == 0)
                {
                    div_five.push_back(a);
                }
                else
                {
                    non_div_five.push_back({i, a});
                }
            }
            else
            {
                odd.push_back(a);
            }
        }
    }

    sort(div_five.begin(), div_five.end(), greater<int>());

    sort(non_div_five.begin(), non_div_five.end(), cmp);

    long long index = 0;
    for (auto a : div_five)
    {
        ans.push_back(a);
    }
    for (auto a : non_div_five)
    {
        ans.push_back(a.second);
    }
    for (auto a : odd)
    {
        ans.push_back(a);
    }

    return ans;
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<int> arr;
        for (long long i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            arr.push_back(temp);
        }

        vector<int> ans = awesomeSort(n, arr);

        for (auto a : ans)
        {
            cout << a << " ";
        }
    }

    return 0;
}