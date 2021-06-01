#include <bits/stdc++.h>

using namespace std;

int t[1001][1001][1001];

int solve(string X, string Y, string Z, int m, int n, int p)
{
    if (m == 0 || n == 0 || p == 0)
    {
        return 0;
    }
    if (t[m][n][p] != -1)
    {
        return t[m][n][p];
    }
    if (X[m - 1] == Y[m - 1] && Y[m - 1] == Z[p - 1])
    {
        t[m][n][p] = 1 + solve(X, Y, Z, m - 1, n - 1, p - 1);
        return t[m][n][p];
    }
    else
    {
        t[m][n][p] = max(solve(X, Y, Z, m - 1, n, p), max(solve(X, Y, Z, m, n - 1, p), solve(X, Y, Z, m, n.p - 1)));
        return t[m][n][p];
    }
}

int main()
{
    memset(t, -1, sizeof(t));
    string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";

    int m = X.length();
    int n = Y.length();
    int p = Z.length();

    cout << solve(X, Y, Z, m, n, p);
}