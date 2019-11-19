/* */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;
typedef vector< int > vi;
typedef pair< int, int > ii;
typedef vector< ii > vii;
typedef vector< ll > vll;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
#else
	#define errp(...)
#endif
#define dbg(x) errp("%s = %s\n", #x, to_string(x).data())
string to_string (string s) { return "\"" + s + "\""; }
template<typename T> string to_string (vector<T>);
template<typename U, typename V> string to_string (pair<U, V> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename T> string to_string (vector<T> v) { string r = "["; for (int i = 0; i < (int)v.size() - 1; i++) r += to_string(v[i]) + ", ";
	if (!v.empty()) r += to_string(v.back()); return r + "]"; }

const int N = 1000100;
bitset<N> isPrime;
vll primes, fac, pw, dl;

void findDiv (ll x, ll i) {
	if (i == (ll)fac.size()) { dl.push_back(x); return; }
	ll k = 1;
	for (ll j = 0; j <= pw[i]; j++) {
		findDiv(x * k, i + 1);
		k *= fac[i];
	}
}

void sieve() {
	isPrime.set();
	for (ll i = 2; i < N; i++) if (isPrime[i])
		for (ll j = i * i; j < N; j += i) isPrime[j] = false;
	for (ll i = 2; i < N; i++) if (isPrime[i]) primes.push_back(i);
}

ll solve(ll x) {
	if (x == 1) return 1;
	for (ll i = 0; primes[i] * primes[i] <= x; i++) {
		ll p = 0;
		while (x % primes[i] == 0) { x /= primes[i]; p++; }
		if (p) { fac.push_back(primes[i]); pw.push_back(p); }
	}
	if (x != 1) { fac.push_back(x); pw.push_back(1); }
	findDiv(1, 0);
	dbg(dl);
	sort(dl.begin(), dl.end());
	reverse(dl.begin(), dl.end());
	dl.pop_back();
	dbg(dl);
	ll k = dl.back();
	set<ll> s;
	for (int i = 0; i < (int)dl.size() - 1; i++) if (dl[i] % k) s.insert(dl[i] % k);
	if (s.empty()) return k;
	return 1;
}

int main () { 
#ifdef XVENOM
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	
	sieve();
	ll n;
	scanf("%lld", &n);
	printf("%lld\n", solve(n));
}