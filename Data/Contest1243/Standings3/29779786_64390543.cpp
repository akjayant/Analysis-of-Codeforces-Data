#include <bits/stdc++.h>

#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define reset(a, v) memset((a), v, sizeof(a))

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

const int N = 1000005;

bitset<N> isPrime;
vi primes;

void sieve() {
	isPrime.set();
	isPrime[0] = isPrime[1] = 0;
	for (ll i = 2; i < N; i++) {
		if (!isPrime[i]) continue;
		primes.push_back(i);
		for (ll j = i * i; j < N; j += i) {
			isPrime[j] = 0;
		}
	}
}

vll getPrimeFactorsCount(ll x) {
	vll ret;
	int idx = 0;
	ll p = primes[idx];
	while (p * p <= x) {
		if (x % p == 0) {
			ret.push_back(p);
			while (x % p == 0) {
				x /= p;
			}
		}
		idx++;
		p = primes[idx];
	}

	if (x != 1) ret.push_back(x);
	return ret;
}

int main() {
	sieve();
	ll n; cin >> n;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	vll res = getPrimeFactorsCount(n);
	if (sz(res) == 1) {
		if (res[0] == n) {
			cout << n << "\n";
		}
		else {
			cout << res[0] << "\n";
		}
	}
	else {
		cout << "1\n";
	} 
	return 0;
}