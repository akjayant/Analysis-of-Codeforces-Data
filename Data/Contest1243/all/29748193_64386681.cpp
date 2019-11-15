#include <bits/stdc++.h>

using namespace std;

const int N = 2e5, INF = 1e9;
long long t, n, a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        string s, t;
        cin >> n >> s >> t;
        vector<pair<int, int>> ans;
        bool bl = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                int j = i + 1;
                for (; j < n; j++)
                {
                    if (s[j] == s[i])
                    {
                        ans.push_back({j, i});
                        swap(s[j], t[i]);
                        break;
                    }
                    else if (t[j] == s[i])
                    {
                        ans.push_back({j, j});
                        ans.push_back({j, i});
                        swap(s[j], t[j]);
                        swap(s[j], t[i]);
                        break;
                    }
                }

                if (j == n)
                {
                    bl = 1;
                    break;
                }
            }
            
        }

        if (bl)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n" << ans.size() << "\n";
            for (auto p : ans)
            {
                cout << p.first + 1 << " " << p.second + 1 << "\n";
            }
        }
    }
}