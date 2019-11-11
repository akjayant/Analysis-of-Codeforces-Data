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

const ll MD = 1e9+7;
const int sz = 1e5+5;

inline ll ADD(ll a, ll b) {
	return (a + b) % MD;
}

inline ll MUL(ll a, ll b) {
	return (a * b) % MD;
}

inline ll powMod(ll a, ll p) {
	ll res = 1;
	for (; p; p >>= 1, a = MUL(a, a)) {
		if (p & 1) res = MUL(res, a);
	}
	return res;
}

ll fac[sz], inv[sz];

void preCompute() {
	fac[0] = 1;
	for (int i = 1; i < sz; ++i) {
		fac[i] = MUL(i, fac[i-1]);
	}
	inv[sz-1] = powMod(fac[sz-1], MD-2);
	for (int i = sz-2; i >= 0; --i) {
		inv[i] = MUL(i+1, inv[i+1]);
		assert(MUL(fac[i], inv[i]) == 1);
	}
}

ll C(ll n, ll k) {
	return MUL(fac[n], MUL(inv[k], inv[n-k]));
}

int main() {
	preCompute();
	string s;
	cin >> s;
	vector< pair<char, ll> > dat;
	char curr = s[0];
	ll cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == curr) {
			++cnt;
		} else {
			dat.pb({curr, cnt});
			cnt = 1;
			curr = s[i];
		}
	}
	dat.pb({curr, cnt});
	cnt = 0;
	ll ans = 1;
	vector<ll> proc;
	for (int i = 0; i < dat.size(); ++i) {
		if (dat[i].fi == 'u' || dat[i].fi == 'n') {
			ll le = dat[i].se;
			ll ri = 0;
			ll hit = 0;
			while (le >= 0) {
				hit = ADD(hit, MUL(fac[le+ri], MUL(inv[le], inv[ri])));
				++ri;
				le -= 2;
			}
			proc.pb(hit);
		} else if (dat[i].fi == 'm' || dat[i].fi == 'w') {
			ans = 0;
		}
	}
	for (auto &it : proc) {
		ans = MUL(ans, it);
	}
	printf("%lld\n", ans);
	return 0;
}