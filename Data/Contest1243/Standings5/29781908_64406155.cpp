#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int>> ans;

int main()
{
    int kk, n;
    string s, t;

    cin >> kk;

    for (int i = 0; i < kk; i++)
    {
        ans.clear();

        cin >> n >> s >> t;

        bool bad = false;

        for (int j = 0; j < n; j++)
        {
            if (s[j] == t[j])
                continue;
            bool f = false;
            for (int k = j + 1; k < n; k++)
            {
                if (t[k] == t[j])
                {
                    f = true;
                    ans.push_back({j, k});
                    swap(s[j], t[k]);
                    break;
                }
            }

            if (f)
            {
                continue;
            }

            for (int k = j + 1; k < n; k++)
            {
                if (s[k] == s[j])
                {
                    f = true;
                    ans.push_back({k, j});
                    swap(s[k], t[j]);
                    break;
                }
            }

            if (f)
                continue;

            for (int k = j + 1; k < n; k++)
            {
                if (t[k] == s[j])
                {
                    f = true;
                    ans.push_back({n - 1, k});
                    ans.push_back({n - 1, j});
                    swap(s[n - 1], t[k]);
                    swap(s[n - 1], t[j]);
                    break;
                }
            }
            if (f)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (s[k] == t[j])
                {
                    f = true;
                    ans.push_back({k, n - 1});
                    ans.push_back({j, n - 1});
                    swap(s[k], t[n - 1]);
                    swap(s[j], t[n - 1]);
                    break;
                }
            }
            if (f)
            {
                continue;
            }
            if (!f)
            {
                bad = true;
                break;
            }
        }
        if (!bad)
        {
            cout << "YES" << endl;
            cout << ans.size() << endl;

            for (auto j : ans)
            {
                cout << j.first + 1 << ' ' << j.second + 1 << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
