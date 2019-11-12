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
        int p1 = -1, p2 = -1;
        bool flg = true;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != t[i] && p1 == -1) p1 = i;
            else if (s[i] != t[i] && p2 == -1) p2 = i;
            else if (s[i] != t[i])
            {
                flg = false;
                break;
            }
        }
        if (!flg || p2 == -1) cout << "NO\n";
        else if (s[p1] == s[p2] && t[p2] == t[p1]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}