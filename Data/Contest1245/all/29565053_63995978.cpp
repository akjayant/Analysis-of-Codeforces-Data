#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(time(0));
#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
// #define int ll

void solve() {
	int a, b;
	cin >> a >> b;
	if (__gcd(a, b) == 1) {
		cout << "Finite" << endl;
	} else {
		cout << "Infinite" << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}