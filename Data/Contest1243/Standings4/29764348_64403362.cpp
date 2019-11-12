#include <bits/stdc++.h>

using namespace std;

int k, n, er;
string s, t;
unordered_map <char, int> u;

int main()
{
  	iostream::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    for (int p = 0 ; p < k ; p++)
    {
        cin >> n >> s >> t;
        u.clear();
        for (int i = 0 ; i < n ; i++)
        {
            u[s[i]]++;
            u[t[i]]++;
        }
        er = 0;
        for (char h = 'a' ; h <= 'z' ; h++)
        {
            if (u[h] % 2 > 0)
                er++;
        }
        if (er > 0)
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        vector <pair <int, int>> ans;
        for (int i = 0 ; i < n ; i++)
        {
            if (s[i] == t[i])
                continue;
            for (int j = i + 1 ; j < n ; j++)
            {
                if (t[i] == t[j])
                {
                    swap(s[i], t[j]);
                    ans.push_back({i, j});
                    break;
                }
                if (s[i] == s[j])
                {
                    swap(t[i], s[j]);
                    ans.push_back({j, i});
                    break;
                }
                else if (t[i] == s[j])
                {
                    ans.push_back({j, i + 1});
                    swap(s[j], t[i + 1]);
                    ans.push_back({i, i + 1});
                    swap(s[i], t[i + 1]);
                    break;
                }
                else if (s[i] == t[j])
                {
                    ans.push_back({i + 1, j});
                    swap(s[i + 1], t[j]);
                    ans.push_back({i + 1, i});
                    swap(s[i + 1], t[i]);
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        for (pair <int, int> g: ans)
            cout << g.first + 1 << " " << g.second + 1 << "\n";
    }
    return 0;
}
