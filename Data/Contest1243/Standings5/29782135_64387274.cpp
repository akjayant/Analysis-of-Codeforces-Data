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

const int N = 10100;
char s[N], t[N];
int n;

bool can() {
	vi pos;
	for (int i = 0; i < n; i++) if (t[i] != s[i]) pos.push_back(i);
	if ((int)pos.size() == 2) {
		if (t[pos[0]] == t[pos[1]] && s[pos[1]] == s[pos[0]]) return true;
		return false;
	}
	if (pos.empty()) return true;
	return false;
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
		scanf("%s%s", s, t);
		printf("%s\n", can() ? "Yes" : "No");
	}
}