#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int q;
    cin >> q;

    while (q--)
    {
        int n;
        string s, t;
        cin >> n >> s >> t;

        vector<int> bad;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
                bad.push_back(i);

        int sz = bad.size();
        for (int i = 0; i < sz; i++)
        {
            if (s[bad[i]] == t[bad[i]])
                continue;

            bool done = false;
            for (int j = i + 1; j < sz; j++)
                if (s[bad[i]] == s[bad[j]])
                {
                    ans.emplace_back(bad[j], bad[i]);
                    swap(s[bad[j]], t[bad[i]]);

                    done = true;
                    break;
                }
            if (!done)
                for (int j = i + 1; j < sz; j++)
                    if (s[bad[i]] == t[bad[j]])
                    {
                        ans.emplace_back(bad[j], bad[j]);
                        ans.emplace_back(bad[j], bad[i]);
                        swap(s[bad[j]], t[bad[j]]);
                        swap(s[bad[j]], t[bad[i]]);

                        done = true;
                        break;
                    }
            if (!done)
            {
                cout << "NO\n";
                goto next;
            }
        }

        if (ans.size() > 2 * n)
            cout << "NO\n";
        else
        {
            cout << "YES\n"
                 << ans.size() << '\n';
            for (auto u : ans)
                cout << u.first + 1 << ' ' << u.second + 1 << '\n';
        }

    next:;
    }

    return 0;
}