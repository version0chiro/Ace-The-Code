#include <bits/stdc++.h>

using namespace std;

class Meetings
{
public:
    int start_time;
    int end_time;

    Meetings(int start_t, int end_t)
    {
        start_time = start_t;
        end_time = end_t;
    }
};

bool compare(Meetings *a, Meetings *b)
{
    if (a->end_time < b->end_time)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void maxMeeting(int s[], int f[], int n)
{
    vector<Meetings *> meets;

    vector<Meetings *> ans;

    for (int i = 0; i < n; i++)
    {
        meets.push_back(new Meetings(s[i], f[i]));
    }

    sort(meets.begin(), meets.end(), compare);

    ans.push_back(meets[0]);

    for (int i=1; i < n; i++)
    {   
        if(meets[i]->start_time >ans.back()->end_time ){
            ans.push_back(meets[i]);
        }
        // cout << a->start_time << " " << a->end_time << "\n";
    }

    for(auto a:ans){
        cout << a->start_time << " " << a->end_time << "\n";
    }

    return;

}

int main()
{

    // Starting time
    int s[] = {1, 3, 0, 5, 8, 5};

    // Finish time
    int f[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(s) / sizeof(s[0]);

    maxMeeting(s, f, n);

    return 0;
}