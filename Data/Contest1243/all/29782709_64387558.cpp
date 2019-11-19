#include <bits/stdc++.h>

using namespace std;

inline void Boost() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}
typedef long long int ll;
typedef long double ld;

int main() {
	Boost();

	ll n; cin >> n;

	vector < ll > divs;
	for (ll d = 2; d * d <= n; ++d) {
		if (n % d == 0) {
			divs.push_back(d);
			while (n % d == 0) {
				n /= d;
			}
		}
	}
	if (n > 1) {
		divs.push_back(n);
	}

	if (divs.size() == 1) {
		cout << divs[0];
	} else {
		cout << 1;
	}
	return 0;
}