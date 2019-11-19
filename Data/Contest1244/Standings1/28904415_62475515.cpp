#include <bits/stdc++.h>

using namespace std;

int n, ans;
char c;

void solve()
{
    cin >> n;
    ans = n;
    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        if (c == '1') ans = max(ans, max(i + 1, n - i) * 2);
    }
    cout << ans << '\n';
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
