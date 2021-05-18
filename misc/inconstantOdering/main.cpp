#include <bits/stdc++.h>

using namespace std;

pair<char, int> getWinner(string inp)
{
    char players[2] = {'I', 'O'};
    int dice = 0;
    int end = inp.length() - 1;
    int start = 0;
    int count = 0;
    char winner;
    int points = 1;
    char curr;
    int mid = start + (end - start) / 2;
    int tempStart = start;
    int tempEnd = end;
    int leftCount = 0;
    int rightCount = 0;

    while (tempStart <= mid)
    {
        if (inp[tempStart] == curr)
        {
            leftCount++;
        }
        tempStart++;
    }

    while (mid < tempEnd)
    {
        if (inp[tempEnd] == curr)
        {
            rightCount++;
        }
        tempEnd--;
    }
    while (start < end)
    {
        curr = players[dice];
        if (curr == inp[start] && curr == inp[end])
        {
            count++;
            if (curr == inp[end - 1])
            {
                points += inp.length() - count;
                winner = curr;
                break;
            }
            else if (curr == inp[start + 1])
            {
                points += inp.length() - count;
                winner = curr;
                break;
            }
            else
            {

                if (leftCount >= rightCount)
                {
                    start++;
                }
                else
                {
                    end--;
                }
            }
        }
        else if (curr == inp[start])
        {
            start++;
            count++;
        }
        else if (curr == inp[end])
        {
            end--;
            count++;
        }
        else if (curr != inp[start] && curr != inp[end])
        {
            winner = players[!dice];
            points += inp.length() - count;
            break;
        }

        dice = !dice;
    }
    if (start >= end)
    {
        winner = players[dice];
    }
    return make_pair(winner, points);
}

int main()
{
    int t;
    int count = 1;
    cin >> t;
    while (t--)
    {
        string input;
        cin >> input;

        auto p = getWinner(input);

        cout << "Case #" << count << ": " << p.first << " " << p.second << endl;

        // cout << "Case #" << count << ": " << ans << endl;
        count++;
    }

    return 0;
}