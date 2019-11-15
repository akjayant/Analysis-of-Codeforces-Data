#include <bits/stdc++.h>
#define ALL(s) (s).begin(), (s).end()
#define rALL(s) (s).rbegin(), (s).rend()
#define sz(s) (int)(s).size()
#define mkp make_pair
#define sqr(s) ((s) * (s))

using namespace std;

typedef complex<int> point;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	string str;
	cin >> str;
	string ans = string(n, '0');
	for (int i = 0; i < n && a > 0; i++) {
		if (str[i] == 'S')
			ans[i] = 'R', a--;
	}
	for (int i = 0; i < n && b > 0; i++) {
		if (str[i] == 'R')
			ans[i] = 'P', b--;
	}
	for (int i = 0; i < n && c > 0; i++) {
		if (str[i] == 'P')
			ans[i] = 'S', c--;
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == '0') {
			if (a)
				ans[i] = 'R', a--;
			else if (b)
				ans[i] = 'P', b--;
			else if (c)
				ans[i] = 'S', c--;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += str[i] == 'R' && ans[i] == 'P';
		cnt += str[i] == 'P' && ans[i] == 'S';
		cnt += str[i] == 'S' && ans[i] == 'R';
	}
	if (cnt < (n + 1) / 2)
		cout << "NO" << endl;
	else
		cout << "YES" << endl << ans << endl;
}	

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--)
		solve();
}
