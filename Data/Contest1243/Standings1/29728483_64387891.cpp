#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define emp emplace
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1123456;

int np[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	ll n; cin >> n;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	vector<ll> primes;
	for (ll i = 2; i <= 1000000; i++) {
		if (np[i] == 0) {
			primes.eb(i);
			for (int j = i+i; j <= 1000000; j += i) {
				np[j] = 1;
			}
		}
	}

	vector<ll> ans;
	for (auto p : primes) {
		if (n % p == 0) {
			ans.eb(p);
		}
		while (n % p == 0) {
			n /= p;
		}
	}
	if (n != 1) ans.eb(n);

	if (ans.size() > 1) {
		cout << 1 << endl;
	} else {
		cout << ans.back() << endl;
	}


	return 0;
}
