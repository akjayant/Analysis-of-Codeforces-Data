#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

using namespace std;

const int inf = 1e18;
const double eps = 1e-6;

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int q;
    cin >> q;
    for (int qi = 0; qi < q; ++qi)
    {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        bool flg = true;
        vector<pair<int, int>> ans;
        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] == t[i]) continue;
            int p = -1;
            for (int j = i + 1; j < n; ++j)
            {
                if (s[j] == s[i])
                {
                    p = j;
                    break;
                }
            }
            if (p != -1)
            {
                swap(s[p], t[i]);
                ans.pb({p, i});
                continue;
            }
            for (int j = i + 1; j < n; ++j)
            {
                if (s[i] == t[j])
                {
                    p = j;
                    break;
                }
            }
            if (p == -1)
            {
                flg = false;
                break;
            }
            swap(s[i + 1], t[p]);
            ans.pb({i + 1, p});
            swap(s[i + 1], t[i]);
            ans.pb({i + 1, i});
        }
        if (!flg || s[n - 1] != t[n - 1]) cout << "NO\n";
        else
        {
            cout << "YES\n";
            cout << sz(ans) << "\n";
            for (auto g : ans) cout << g.ff + 1 << " " << g.ss + 1 << "\n";
        }
        /*while (true)
        {
            int p1 = -1, p2 = -1;
            for (int i = 0; i < n; ++i)
            {
                if (s[i] != t[i] && p1 == -1)
                {
                    p1 = i;
                    continue;
                }
                if (s[p1] == s[i] && t[p1] == t[i])
                {
                    p2 = i;
                    break;
                }
            }
            if (p1 == -1) break;
            if (p2 == -1)
            {
                flg = false;
                break;
            }
            swap(s[p1], t[p2]);
            ans.pb({p1, p2});
        }
        if (!flg)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << sz(ans) << "\n";
        for (auto g : ans) cout << g.ff + 1 << " " << g.ss + 1 << "\n";*/
    }
    return 0;
}