#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 1; i <= k; i++)
    {
        int n;
        cin >> n;

        string s,t;

        cin >> s;
        cin >> t;

        vector<int> diff;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                diff.push_back(i);
            }
        }

        if (diff.size() == 2)
        {
            int d1 = diff[0];
            int d2 = diff[1];

            if (t[d1] == t[d2] && s[d2] == s[d1])
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (diff.size() == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
