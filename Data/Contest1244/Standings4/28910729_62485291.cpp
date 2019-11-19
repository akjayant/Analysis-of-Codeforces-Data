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
const int mx = 500001;

int get(int a, int b, int & x, int & y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = get(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, p, w, d;
    cin >> n >> p >> w >> d;
    for (int y = 0; y <= mx; ++y)
    {
        if (y * d > p) break;
        if ((p - y * d) % w) continue;
        int x = (p - y * d) / w;
        if (x + y > n) continue;
        cout << x << " " << y << " " << n - x - y << "\n";
        return 0;
    }
    cout << -1;
    return 0;
}