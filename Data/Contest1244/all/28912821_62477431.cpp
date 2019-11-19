#include <bits/stdc++.h>

using namespace std;

#define int long long

pair<int, int> gcd(int a, int b, int xa, int ya, int xb, int yb)
{
    if (b == 0)
    {
        return {xa, ya};
    }
    int k = a / b;
    return gcd(b, a % b, xb, yb, xa - k * xb, ya - k * yb);
}

pair<int, int> diaff(int a, int b, int c)
{
    char f1, f2;
    f1 = 0, f2 = 0;
    if (c < 0)
    {
        c *= 1, a *= 1, b *= 1;
    }
    if (a < 0) f1 = 1, a = -a;
    if (b < 0) f2 = 1, b = -b;
    int d = __gcd(a, b);
    if (c % d)
    {
        return {-LLONG_MAX, -LLONG_MAX};
    }
    auto imp = gcd(a, b, 1, 0, 0, 1);
    imp.first *= c / d, imp.second *= c / d;
    if (f1)
        imp.first *= -1;
    if (f2)
        imp.second *= -1;
    return imp;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef arrias
    freopen("true.txt", "r", stdin);
#endif
    int n, p, w, d;
    cin >> n >> p >> w >> d;

    bool f = false;

    for (int y = 0; y <= w; ++y) {
        int cnt = p - y * d;
        if (cnt % w == 0 && cnt >= 0 && n >= cnt / w + y) {
            f = true;
            cout << cnt / w << " " << y << " " << n - cnt / w - y << "\n";
            break;
        }
    }

    if (!f) {
        cout << -1;
    }
    return 0;
}
