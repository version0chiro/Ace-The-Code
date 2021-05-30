#include <bits/stdc++.h>

using namespace std;

unsigned long int solve(unsigned int n)
{
    unsigned long int catalan[n + 1];

    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }

    return catalan[n];
}

int main()
{
    int n;
    cin >> n;
    for (unsigned int i = 0; i < n; i++)
    {
    cout <<solve(i)<<" ";
    }
}