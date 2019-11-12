#include <bits/stdc++.h>
using namespace std;

int q, n;
string s, t;
int f[300];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> q;
    while (q--)
    {
        cin >> n >> s >> t;

        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
            {
                f[s[i]]++;
                f[t[i]]++;
            }

        bool ans = 1;
        for (int i = 'a'; i <= 'z'; i++)
            if (f[i] % 2)
                ans = 0;
        if (!ans)
        {
            cout << "No\n";
            continue;
        }

        vector < pair<int, int> > mutari;

        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
            {
                // aduc pe t[i] un s[i]

                for (int j = i + 1; j < n; j++)
                {
                    if (s[j] == s[i])
                    {
                        // s[j] cu t[i]
                        swap(s[j], t[i]);
                        mutari.push_back({j + 1, i + 1});
                        break;
                    }
                    if (t[j] == s[i])
                    {
                        // s[j] cu t[j]; s[j] cu t[i];
                        swap(s[j], t[j]);
                        swap(s[j], t[i]);
                        mutari.push_back({j + 1, j + 1});
                        mutari.push_back({j + 1, i + 1});
                        break;
                    }
                }
            }

        cout << "Yes\n";
        cout << mutari.size() << "\n";
        for (auto x: mutari)
            cout << x.first << " " << x.second << "\n";

    }

    return 0;
}