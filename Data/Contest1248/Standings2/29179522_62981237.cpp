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

const int N = 100010;
ll a[N], n;

int main () { 
#ifdef XVENOM
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	scanf("%lld", &n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
	sort(a, a + n);
	ll x = 0, y = 0;
	for (int i = 0; i < n / 2; i++) x += a[i];
	for (int i = n / 2; i < n; i++) y += a[i];
	printf("%lld\n", x * x + y * y);
}