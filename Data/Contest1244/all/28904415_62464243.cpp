#include <bits/stdc++.h>

using namespace std;

int a, b, c, d, k;

void solve()
{
    cin >> a >> b >> c >> d >> k;
    a = (a / c) + !!(a % c);
    b = (b / d) + !!(b % d);
    if (a + b > k)
    {
        cout << "-1\n";
        return;
    }
    cout << a << ' ' << b << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.inp", "r", stdin);
	//freopen("out.out", "w", stdout);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
