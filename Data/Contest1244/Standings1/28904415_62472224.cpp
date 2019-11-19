#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	long long n, p;
	int w, d;
	cin >> n >> p >> w >> d;
	long long res = min(n, p / w), cur = p - (res + 1) * w;
	for (int i = 0, lim = min((long long) d / __gcd(d, w), res + 1); i < lim; ++i)
    {
        cur += w;
        if (cur % d) continue;
        if (cur / d > n - res + i) continue;
        cout << res - i << ' ' << cur / d << ' ' << n - res + i - (cur / d);
        return 0;
    }
    cout << -1;
    return 0;
}
