#include <bits/stdc++.h>

#define boost ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
const int N = 1e6 + 55;
const int mod = 1e9 + 7;
const long long INF = 1e18 + 12;
const int inf = 1e9;

int main () {
	boost;
	long long x;
	cin >> x;
	if (x == 1) return cout << 1, 0;
	vector <long long> v;
	for (long long i = 2 ; i * i <= x ; ++ i) {
		if (x % i == 0) {
			v.push_back (i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) v.push_back (x);
	long long p = v[0];
	for (long long i : v) p = __gcd (p, i);
	cout << p;
}