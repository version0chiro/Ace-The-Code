#include <bits/stdc++.h>

using namespace std;

void words_count(string str)
{
    string temp = "";
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char a = str[i];
        if (i == 0 && str[i] == ' ')
        {
            i++;
            continue;
        }
        if (a == ' ')
        {
            while (i + 1 < str.length() && str[i + 1] == ' ')
            {
                i++;
                a = str[i];
            }
            if (temp != "")
            {

                cout << temp << " \n";
                temp = "";
                count++;
            }
        }
        else
        {
            temp += a;
        }
    }

    cout << temp << " \n";

    cout << "numbr of words = " << count;
}

int main()
{
    string str = "   i  am sachin   singh  ";

    words_count(str);
    return 0;
}