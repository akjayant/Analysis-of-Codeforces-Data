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
	int a, b;
	cin >> a >> b;
	if (__gcd(a, b) == 1)
		cout << "Finite" << endl;
	else
		cout << "Infinite" << endl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	// freopen("input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--)
		solve();
}
