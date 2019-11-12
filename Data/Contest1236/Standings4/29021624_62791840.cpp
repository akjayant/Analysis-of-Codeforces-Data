#include <bits/stdc++.h>
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define out(t, a) copy(all(a), ostream_iterator<t>(cout, " ")); cout << "\n";
#define int long long
// #define DEBUG

using namespace std;
 
void set_program() {
	#ifdef DEBUG
		freopen ("test.in", "r", stdin);
		freopen ("test.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
 
// typedef long long ll;

// const int INF = 1e9 + 1;

const int MOD = 1e9 + 7;

int bin_pow(int a, int k) {
	if (!k) {
		return 1;
	}
	if (k == 1) {
		return a;
	}
	int res = bin_pow(a, k / 2);
	if (k % 2) {
		return (((res * res) % MOD) * a) % MOD;
	} else {
		return (res * res) % MOD;
	}
}
 
main() {
	set_program();
	int n, m;
	cin >> n >> m;
	int res = (bin_pow(2, m) - 1 + MOD) % MOD;
	res = bin_pow(res, n);
	cout << res << "\n";
 	return 0;
}
