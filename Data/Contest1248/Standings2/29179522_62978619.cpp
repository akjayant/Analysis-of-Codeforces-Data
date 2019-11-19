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
string to_string (char s) { return string(1, s); }
string to_string (string s) { return "\"" + s + "\""; }
template<typename T> string to_string (vector<T>);
template<typename U, typename V> string to_string (pair<U, V> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template<typename T> string to_string (vector<T> v) {
	string res = "["; for (int i = 0; i < (int)v.size() - 1; i++) res += to_string(v[i]) + ", ";
	if (!v.empty()) res += to_string(v.back());	res += "]"; return res; }

void solve() {
	int n, m, x;
	ll on = 0, om = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x & 1) on++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (x & 1) om++;
	}
	printf("%lld\n", om * on + (n - on) * (m - om));
}

int main () { 
#ifdef XVENOM
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	scanf("%d", &tc);
	while (tc--) solve();
}