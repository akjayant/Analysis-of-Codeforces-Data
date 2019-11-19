#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	while (b != 0) {
		ll t = a;
		a = b;
		b = t % b;
	}
	return a;
}

int main() {
	ll n;
	while (cin >> n) {
//		cerr << "n = " << n << endl;
		ll res = n;
		ll d = 2;
		while (d * d <= n) {
			if (n % d == 0) {
//                cerr << res << " " << d << endl;
    			res = gcd(res, d);
    			res = gcd(res, n / d);
                if (res == 1) {
                    break;
                }
			}
			d += 1;
		}
		cout << res << endl;
	}
    return 0;
}
