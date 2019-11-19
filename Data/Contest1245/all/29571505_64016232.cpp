/* Bismillahirrahmanirrahim */
/* Author : Jehian Norman Saviero (@Reiva5) */
#include <bits/stdc++.h>
 
// MACROS SAMPAH
#define Jehian using
#define Norman namespace
#define Saviero std
 
Jehian Norman Saviero;
 
// MACROS TYPE
typedef long l;
typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<l,l> pl;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<l> vl;
typedef vector<ll> vll;
 
// MACROS FOR PRINT
#define nl printf("\n")
 
// MACROS FOR ATTRIBUTE
#define fi first
#define se second
 
// MACROS FOR FUNCTION AND METHOD
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ALL(x) (x).begin(), (x).end()
#define ALLN(x,n) (x), (x)+(n)
#define CUBE(x) (SQR(x)*(x))
#define SET(x,y) for (int _qwe = sizeof(x)/sizeof(x[0]); _qwe; ) x[--_qwe] = (y)
#define SQR(x) ((x)*(x))
#define SSORT(x,sz) sort(ALLN(x,sz))
#define RESET(x) memset((x), 0, sizeof(x))
#define VSORT(x) sort(ALL(x))
 
// MACROS READ INPUT
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%ld", &x)
#define scll(x) scanf("%lld", &x)
#define scd(x) scanf("%lf", &x)
#define scld(x) scanf("%Lf", &x)
#define scul(x) scl(x)
#define scull(x) scll(x)

vector< pair<ll, pll> > cEdges;
vll pset;

void initSet(ll n) {
	pset.resize(n+1);
	for (ll i = 0; i < pset.size(); ++i) {
		pset[i] = i;
	}
}

ll findSet(ll p) {
	return pset[p] == p ? p : pset[p] = findSet(pset[p]);
}

bool isSameSet(ll u, ll v) {
	return findSet(u) == findSet(v);
}

void joinSet(ll u, ll v) {
	pset[findSet(v)] = findSet(u);
}

ll dist(pll &A, pll &B) {
	return abs(A.fi-B.fi) + abs(A.se-B.se);
}

int main() {
	ll n;
	scll(n);
	ll source = n;
	initSet(n);
	vector<pll> dat(n);
	for (ll i = 0; i < n; ++i) {
		scll(dat[i].fi), scll(dat[i].se);
	}
	vll c(n), k(n);
	cEdges.resize(n * (n + 1)/2);
	for (ll i = 0; i < n; ++i) {
		scll(c[i]);
	}
	for (ll i = 0; i < n; ++i) {
		scll(k[i]);
	}
	ll cnt = 0;
	for (ll i = 0; i < n; ++i) {
		for (ll j = i + 1; j < n; ++j) {
			cEdges[cnt++] = {dist(dat[i], dat[j]) * (k[i] + k[j]), {i, j}};
		}
	}
	for (ll i = 0; i < n; ++i) {
		cEdges[cnt++] = {c[i], {source, i}};
	}
	assert(cnt == cEdges.size());
	VSORT(cEdges);
	ll ans = 0;
	vll power;
	vector<pll> edges;
	for (ll i = 0; i < cnt; ++i) {
		if (!isSameSet(cEdges[i].se.fi, cEdges[i].se.se)) {
			joinSet(cEdges[i].se.fi, cEdges[i].se.se);
			if (cEdges[i].se.fi == source) {
				power.pb(cEdges[i].se.se);
			} else {
				edges.pb(cEdges[i].se);
			}
			ans += cEdges[i].fi;
		}
	}
	printf("%lld\n", ans);
	printf("%ld\n", power.size());
	string sp = "";
	for (ll i = 0; i < power.size(); ++i) {
		printf("%s%lld", sp.c_str(), power[i]+1);
		sp = " ";
	}
	printf("\n");
	printf("%ld\n", edges.size());
	for (ll i = 0; i < edges.size(); ++i) {
		printf("%lld %lld\n", edges[i].fi+1, edges[i].se+1);
	}
	printf("\n");
	return 0;
}