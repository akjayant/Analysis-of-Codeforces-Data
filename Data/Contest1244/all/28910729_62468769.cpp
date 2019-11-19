#include <bits/stdc++.h>

#define int long long
#define double long double
#define ff first
#define ss second
#define pb push_back
#define pf push_front
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
        string t;
        cin >> t;
        int f = -1, s = -1;
        for (int i = 0; i < n; ++i)
        {
            if (t[i] == '1')
            {
                s = i;
                if (f == -1) f = i;
            }
        }
        int ans = n;
        if (s != -1) ans = max(ans, 2 * (s + 1));
        if (f != -1) ans = max(ans, 2 * (n - 1 - f + 1));
        cout << ans << "\n";
    }
    return 0;
}