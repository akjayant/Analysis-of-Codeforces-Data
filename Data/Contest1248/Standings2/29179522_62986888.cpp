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
const ll MOD = (ll)1e9 + 7;
ll f[N];
ll mulMod (ll a, ll b) { return ((a % MOD) * (b % MOD)) % MOD; }
ll addMod (ll a, ll b) { return (a + b) % MOD; }
ll subMod (ll a, ll b) { return (a - b + MOD) % MOD; }


int main () { 
#ifdef XVENOM
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
#endif

	f[0] = f[1] = 1;
	for (int i = 2; i < N; i++) f[i] = addMod(f[i - 1], f[i - 2]);
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%lld\n", mulMod(2, subMod(addMod(f[n], f[m]), 1)));
}