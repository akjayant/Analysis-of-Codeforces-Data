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

const ll MOD = (ll)1e9 + 7;
const int N = 100010;
ll f[N];
char s[N];
ll addMod (ll a, ll b) {
	ll res = a + b;
	if (res > MOD) res -= MOD;
	return res;
}

ll mulMod (ll a, ll b) {
	return ((a % MOD) * (b % MOD)) % MOD;
}	

ll solve() {
	int n = strlen(s), cnt = 0, last = 0;
	ll res = 1;
	for (int i = 0; i < n; i++) if (s[i] == 'w' || s[i] == 'm') return 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'n') {
			if (last == s[i]) cnt++;
			else { res = mulMod(res, f[cnt]); cnt = 1; last = s[i]; }
		}
		else if (s[i] == 'u') {
			if (last == s[i]) cnt++;
			else { res = mulMod(res, f[cnt]); cnt = 1; last = s[i]; }
		}
		else {
			res = mulMod(res, f[cnt]);
			cnt = 0;
		}
	}
	res = mulMod(res, f[cnt]);
	return res;
}
int main () { 
#ifdef XVENOM
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	
	f[0] = f[1] = 1;
	for (int i = 2; i < N; i++) f[i] = addMod(f[i - 1], f[i - 2]);

	scanf("%s", s);
	printf("%lld\n", solve());
}