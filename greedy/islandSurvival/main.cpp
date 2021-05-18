#include <bits/stdc++.h>

using namespace std;

void findSurvival(int S, int N, int M)
{

    if (((N * 6) < (7 * M) && S > 6) || M > N)
    {
        cout << "No";
    }
    else
    {
        int days = (M * S) / N;

        if (((M * S) % N != 0))
        {
            days++;
        }

        cout << "Yes " << days << "\n";
    }
}

int main()
{
    int S, N, M;
    cin >> S >> N >> M;

    findSurvival(S, N, M);

    return 0;
}