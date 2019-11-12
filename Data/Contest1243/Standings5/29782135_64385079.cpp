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

const int N = 100;
char s[N], t[N];
int n;
vii res;

bool can() {
	res.clear();
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) continue;
		int k = -1;
		for (int j = i + 1; j < n; j++) if (t[j] == s[i]) { k = j; break; }
		if (k != -1) {
			swap(s[i], t[i]);
			swap(s[i], t[k]);
			res.push_back({i, i});
			res.push_back({i, k});
			continue;
		}
		for (int j = i + 1; j < n; j++) if (s[j] == s[i]) { k = j; break; }
		if (k == -1) return false;
		swap(s[k], t[i]);
		res.push_back({k, i});
	}
	assert(strcmp(s, t) == 0);
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
		scanf("%s%s", s, t);
		if (can()) {
			printf("Yes\n");
			printf("%d\n", (int)res.size());
			for (int i = 0; i < (int)res.size(); i++) printf("%d %d\n", res[i].first + 1, res[i].second + 1);
		}
		else printf("No\n");
	}
}