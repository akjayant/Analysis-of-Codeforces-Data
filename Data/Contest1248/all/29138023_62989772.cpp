#include <bits/stdc++.h>

#define int long long
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, x) for(int i = 0; i < x; i++)
#define rforn(i, x) for(int i = x - 1; i >= 0; i--)

using namespace std;

template<typename T> void print(T a)
{
    for (auto x : a)
        cout << x << ' ';
    cout << endl;
}

const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (a + b) % MOD;
}

int mul(int a, int b) {
	return (a * b) % MOD;
}

int solve(int n) {
	vector<int> dp1(n, 0), dp2(n, 0);
	dp1[0] = 1;
	dp2[0] = 0;

	for (int i = 1; i < n; i++) {
		dp1[i] = add(dp1[i - 1], dp2[i - 1]);
		dp2[i] = dp1[i - 1];
	}

	return add(dp1[n - 1], dp2[n - 1]);
}

signed main()
{
    //freopen("test.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = add(solve(n), solve(m));
    ans--;
    if (ans < 0)
    	ans += MOD;
    ans = mul(ans, 2);
    cout << ans;
    return 0;
}
