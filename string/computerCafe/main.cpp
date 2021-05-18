#include <bits/stdc++.h>

using namespace std;

int findCount(int n, string seq)
{
    unordered_map<char, int> mMap;
    int result = 0;
    int computerCount = n;
    for (int i=0;i<seq.length();i++)   
    {
        auto s=seq[i];
        if (mMap[s] == 0)
        {
            if (computerCount > 0)
            {
            cout << s << " will start using" << endl;
                mMap[s]++;
                computerCount--;
            }else{
                result++;
                cout<<s<<" could not use computer"<<endl;
                mMap[s]=-1;
                // i++;
            }
        }
        else if(mMap[s]!=-1)
        {
            if (mMap[s] == 1)
            {
                cout << s << " will stop using" << endl;
                computerCount++;
                mMap[s]--;
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    string seq;
    cin >> seq;
    cout << findCount(n, seq);

    return 0;
}