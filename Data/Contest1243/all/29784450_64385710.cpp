#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s;
        cin >> t;
        int diff = 0;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                a.push_back(i);
            }
        }
        if (a.size() == 0)
            cout << "YES" << endl;
        else if (a.size() == 1)
            cout << "NO" << endl;
        else if (a.size() > 2)
            cout << "NO" << endl;
        else
        {
            if (s[a[0]] == s[a[1]] && t[a[0]] == t[a[1]])
                cout << "YES" << endl;
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}