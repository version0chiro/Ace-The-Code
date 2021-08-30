#include <bits/stdc++.h>

using namespace std;

int t[1001];

int solve(const vector<int> &HighScores, int i, int n)
{
    if (i >= n)
        return 0;

    if (t[i]!=-1) return t[i];

    int left = solve(HighScores, i + 2, n) + HighScores[i];
    int right = solve(HighScores, i + 1, n);

    return t[i]=max(left, right);
}
int GetMaxValue(const vector<int> &HighScores)
{
    memset(t, -1, sizeof(t));
    return solve(HighScores, 0, HighScores.size());
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << GetMaxValue(v);
    return 0;
}