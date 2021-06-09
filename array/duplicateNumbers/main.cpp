#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    set<int> seenNumbers;
    for (auto a : nums)
    {
        // cout<<a;
        if (seenNumbers.find(a) != seenNumbers.end())
        {
            return a;
        }
        else
        {
            seenNumbers.insert(a);
        }
    }
    return -1;
}

int findDuplicateConstantSpace(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow)
    {
        fast = nums[fast];
        slow = nums[slow];
    }

    return slow;
}

int main()
{

    int n;
    int temp;
    cin >> n;
    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }

    cout << "duplicate number=>" << findDuplicate(array) << endl;
    return 0;
}