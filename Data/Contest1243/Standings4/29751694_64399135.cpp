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
    /*for (int n = 1; n <= 50; ++n)
    {
        vector<int> v;
        for (int d = 2; d <= n; ++d)
        {
            if (n == d) continue;
            if (n % d == 0) v.pb(d);
            if (n % d == 0 && (n / d) != d) v.pb(n / d);
        }
        vector<int> c(n + 1);
        for (int i = 0; i < n + 1; ++i) c[i] = i;
        for (int i = 1; i <= n; ++i)
        {
            for (int d : v)
            {
                for (int j = i; j <= n; j += d)
                {
                    c[j] = min(c[j], c[i]);
                    c[i] = min(c[i], c[j]);
                }
            }
        }
        set<int> s;
        for (int x = 1; x <= n; ++x) s.insert(c[x]);
        cout << n << ": " << sz(s) << "\n";
    }*/
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    set<int> d;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i) continue;
        d.insert(i);
        while (n % i == 0) n /= i;
    }
    if (n != 1) d.insert(n);
    if (sz(d) > 1) cout << 1;
    else cout << *(d.begin());
    return 0;
}