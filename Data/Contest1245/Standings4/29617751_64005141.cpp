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

const int N = 110;
char p[N], q[N];
int a, b, c, n;

bool can() {
	int ns = 0, nr = 0, np = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] == 'S') ns++;
		else if (p[i] == 'R') nr++;
		else np++;
	}
	int mx = min(ns, a) + min(nr, b) + min(np, c);
	if (mx < (n - 1) / 2 + 1) return false;
	int cr = min(ns, a), cp = min(nr, b), cs = min(np, c);
	a -= cr; b -= cp; c -= cs;
	memset(q, 0, sizeof q);
	for (int i = 0; i < n; i++) {
		if (p[i] == 'S' && cr) { q[i] = 'R'; cr--; }
		if (p[i] == 'R' && cp) { q[i] = 'P'; cp--; }
		if (p[i] == 'P' && cs) { q[i] = 'S'; cs--; }
	}
	for (int i = 0; i < n; i++) if (!q[i]) {
		if (a) { q[i] = 'R'; a--; }
		else if (b) { q[i] = 'P'; b--; }
		else if (c) { q[i] = 'S'; c--; }
	}
	return true;
}

int main () { 
#ifdef XVENOM
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif
	
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		scanf("%d%d%d", &a, &b, &c);
		scanf("%s", p);
		if (can()) printf("YES\n%s\n", q);
		else printf("NO\n");
	}
}