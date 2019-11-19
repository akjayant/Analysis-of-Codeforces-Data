#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <queue>
#include <iomanip>
using namespace std;
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define pb push_back
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long double ld;

ll bin_pow(ll a, ll n, ll mod) {
	if (n == 0)return 1;
	if (n & 1) {
		return (a * bin_pow(a, n - 1, mod)) % mod;
	}
	else {
		ll tmp = bin_pow(a, n / 2, mod);
		return (tmp * tmp) % mod;
	}
}

int main() {
	fastio;
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		ll cnt1[] = { 0,0 }, cnt2[] = { 0,0 };
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			cnt1[x % 2]++;
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int y;
			cin >> y;
			cnt2[y % 2]++;
		}
		cout << cnt1[0] * cnt2[0] + cnt1[1] * cnt2[1] << '\n';
	}
	return 0;
}