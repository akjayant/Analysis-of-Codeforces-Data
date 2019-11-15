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
        vector<pair<char, char>> v;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != t[i])
            {
                v.push_back({s[i], t[i]});
            }
        }

        if (v.size() == 0)
        {
            cout << "Yes\n";
        }
        else if (v.size() == 2 && v[0].first == v[1].first && v[0].second == v[1].second)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
        
    }
}