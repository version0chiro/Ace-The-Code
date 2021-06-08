#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        a.push_back(temp);
    }
    cin>>m;
    vector<int> b;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        b.push_back(temp);
    }

    // cout << a.size() << "\n";
    int i = 0, j = 0;

    int lenA = a.size();
    int lenB = b.size();

    while (i < a.size() && j < b.size())
    {

        if (a[i] == b[j])
        {
            i++;
            j++;
        }
        else
        {
            if (a[i] > b[j])
            {
                // cout << a[i] << " " << b[j] << "\n";
                int temp = j + 1;
                while (temp < b.size() && a[i] > b[j])
                {
                    b[j] += b[temp];
                    b.erase(b.begin() + temp);
                    temp++;
                }
                if (a[i] > b[j])
                {
                    break;
                }
            }
            else if (b[j] > a[i])
            {
                // cout << a[i] << " " << b[j] << "\n";

                int temp = i + 1;
                while (temp < a.size() && a[i] < b[j])
                {
                    a[i] += a[temp];
                    a.erase(a.begin() + temp);
                    temp++;
                }
                if (b[j] > a[i])
                {
                    break;
                }
            }
        }
    }

    if (a.size() == b.size())
    {
        cout << a.size();
    }
    else
    {
        cout << -1;
    }

    // cout << endl;
    // for (auto p : a)
    // {
    //     cout << p << " ";
    // }

    // cout << endl;

    // for (auto p : b)
    // {
    //     cout << p << " ";
    // }
    return 0;
}