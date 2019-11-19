//
// Devshoo / Indigo203
// The problem is about counting the number of some combinatoric objects. Thus, dynamic programming is always the answer.

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cctype>
#include <functional>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

#ifndef MACRO_UNUSE
#define F "%lld"
#define rd(x) scanf(F, &(x))
#define rd2(x, y) scanf(F F, &x, &y)
#define rd3(x, y, z) scanf(F F F, &x, &y, &z)
#define rds(x) scanf("%s", x)
#define pt(x) printf(F "\n", x)
#define df(x) ll x; rd(x)
#define df2(x, y) ll x,y; rd2(x, y)
#define df3(x, y, z) ll x,y,z; rd3(x, y, z)
#define INF 0x3f3f3f3f3f3f3f3fll
#define fori(i, n) for(ll i = 1; i <= n; i++)
#define forn(i, n) for(ll i = 0; i < n; i++)
#define rdn(s, n) forn(__i, (n)) rd((s)[__i]);
#define ptn(s, n) forn(__i, (n)) printf(F "%c", (s)[__i], __i + 1 == (n) ? 10 : 32);
#endif

const ll mod = 1e9 + 7;

#define N (ll(1e5) + 7)

ll a[2];
ll b[2];

int main() {
	df(t);
	
	while(t--) {
		df(n);
		a[0] = a[1] = b[0] = b[1] = 0;
		forn(i, n) {
			df(ai);
			a[ai%2]++;
		}
		df(m);
		forn(i, m) {
			df(bi);
			b[bi%2]++;
		}
		pt(a[0]*b[0] + a[1] * b[1]);
	}
	
	
    return 0;
}

