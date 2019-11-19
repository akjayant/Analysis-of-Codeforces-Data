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
    for (int i = 0; i < q; ++i)
    {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = (a + c - 1) / c;
        int y = (b + d - 1) / d;
        if (x + y > k) cout << "-1\n";
        else cout << x << " " << y << "\n";
    }
    return 0;
}