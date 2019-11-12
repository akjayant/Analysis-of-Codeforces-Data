#pragma GCC optimize("-Ofast")

#include <bits/stdc++.h>

#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define ld long double
#define sqr(x) (x) * (x)

using namespace std;

const int maxa = 1e6 + 5;
int lp[maxa];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    for(int ii = 0; ii < k; ++ii)
    {
        int n;
        string s, t;
        cin >> n >> s >> t;
        int cnt[26];
        for(int i = 0; i < 26; ++i)
            cnt[i] = 0;
        for(int i = 0; i < n; ++i)
        {
            cnt[int(s[i] - 'a')]++;
            cnt[int(t[i] - 'a')]++;
        }
        bool f = true;
        string str;
        for(int i = 0; i < 26; ++i)
            if (cnt[i] % 2 == 1) f = false;
        if (!f)
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        vector <pair <int, int>> ans;
        f = true;
        for(int i = 0; i < n; ++i)
        {
            if (s[i] != t[i])
            {
                for(int j = i + 1; j < n; ++j)
                {
                    if (s[j] == s[i])
                    {
                        ans.pb({j, i});
                        swap(s[j], t[i]);
                        break;
                    }
                    if (t[j] == t[i])
                    {
                        ans.pb({i, j});
                        swap(s[i], t[j]);
                        break;
                    }
                }
                if (s[i] == t[i]) continue;
                for(int j = i + 1; j < n; ++j)
                {
                    if (t[j] == s[i])
                    {
                        ans.pb({j, j});
                        swap(s[j], t[j]);
                        ans.pb({j, i});
                        swap(s[j], t[i]);
                        break;
                    }
                    if (s[j] == t[i])
                    {
                        ans.pb({j, j});
                        swap(s[j], t[j]);
                        ans.pb({i, j});
                        swap(s[i], t[j]);
                        break;
                    }
                }
            }
        }
        cout << int(ans.size()) << '\n';
        for(auto i : ans)
            cout << i.F + 1 << ' ' << i.S + 1 << '\n';
    }
    return 0;
}
