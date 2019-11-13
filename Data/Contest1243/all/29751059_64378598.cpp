#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;

    while (q--)
    {
        int n;
        string s, t;
        cin >> n >> s >> t;

        vector<int> bad;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
                bad.push_back(i);
        if (bad.size() != 2)
            cout << "NO\n";
        else if (s[bad[0]] == s[bad[1]] && t[bad[0]] == t[bad[1]])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}