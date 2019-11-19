#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;
using ii = pair<int, int>;

vector<ll> fac(ll x) {
	vector<ll> ans;

	ll k = x;
	for (ll i = 2; i*i <= x; i++) {
		if (k%i == 0) {
			ans.push_back(i);
			do {
				k /= i;
			} while (k%i == 0);
		}
	}

	if (k != 1) ans.push_back(k);

	return ans;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	
	ll n;
	cin >> n;

	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	
	auto f = fac(n);

	if (f.size() > 1) {
		cout << 1 << "\n";
	} 
	else {
		cout << f.front() << "\n";
	}
}