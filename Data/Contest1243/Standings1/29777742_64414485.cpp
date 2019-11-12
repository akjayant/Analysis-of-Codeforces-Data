#include <bits/stdc++.h>

using namespace std;
#define taskname "cf1243"
typedef pair < int, int > ii;

int T, n, k, ans, cur;
string s, t;
int cnt[255];
int cnt2[255];
vector < ii > res;

int main()
{
    #ifdef duyenn
        freopen (taskname".inp", "r", stdin);
        freopen (taskname".out", "w", stdout);
    #endif // duyenn
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();
    for (cin >> T; T--;)
    {
        ans = 0;
        res.clear();
        cin >> n >> s >> t;
        for (int i = 'a'; i <= 'z'; i++)
            cnt[i] = cnt2[i] = 0;
        for (int i = 0; i < n; i++)
            cnt[s[i]]++;
        for (int i = 0; i < n; i++)
            cnt2[t[i]]++;
        for (int i = 0; i < n; i++)
            if (s[i] != t[i])
            {
                cur = max(cur, i);
                for (int j = i + 1; j < n; j++)
                {
                    if (s[i] != t[i])
                    {
                        if (cnt[s[i]] % 2 == cnt2[t[i]] % 2)
                            ans++;
                    }
                    if (t[i] == t[j])
                    {
                        res.push_back(ii(i, j));
                        swap(s[i], t[j]);
                        break;
                    }
                    else if (s[j] == t[i])
                    {
                        res.push_back(ii(i, i));
                        swap(s[i], t[i]);
                        res.push_back(ii(j, i));
                        swap(s[j], t[i]);
                        break;
                    }
                    else if (s[i] == t[j])
                    {
                        res.push_back(ii(i, i));
                        swap(s[i], t[i]);
                        res.push_back(ii(i, j));
                        swap(s[i], t[j]);
                        break;
                    }
                }
            }
        res.push_back(ii(ans, cur));
        if (s == t)
        {
            cout << "Yes\n";
            cout << res.size() - 1 << "\n";
            for (int i = 0; i < res.size() - 1; i++)
                cout<< res[i].first + 1 << " " << res[i].second + 1 << '\n';
        }
        else
            cout << "No\n";
    }
}
