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
        vector<int> v(n);
        for (int i = 0; i < n; ++i) cin >> v[i];
        sort(all(v));
        reverse(all(v));
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, min(i + 1, v[i]));
        }
        cout << ans << "\n";
    }
    return 0;
}