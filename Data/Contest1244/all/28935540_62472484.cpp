#include <bits/stdc++.h>

using namespace std;

#define FILE(Name) freopen(Name".in", "r", stdin), freopen(Name".out", "w", stdout)

namespace io {
	const int __SIZE = (1 << 21) + 1;
	char ibuf[__SIZE], *iS, *iT, obuf[__SIZE], *oS = obuf, *oT = oS + __SIZE - 1, __c, qu[55]; int __f, qr, _eof;
	#define Gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, __SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () { fwrite (obuf, 1, oS - obuf, stdout), oS = obuf; }
	inline void gc (char &x) { x = Gc(); }
	inline void pc (char x) { *oS ++ = x; if (oS == oT) flush (); }
	inline void pstr (const char *s) { int __len = strlen(s); for (__f = 0; __f < __len; ++__f) pc (s[__f]); }
	inline void gstr (char *s) { for(__c = Gc(); __c < 32 || __c > 126 || __c == ' ';)  __c = Gc();
		for(; __c > 31 && __c < 127 && __c != ' '; ++s, __c = Gc()) *s = __c; *s = 0; }
	template <class I> inline bool gi (I &x) { _eof = 0;
		for (__f = 1, __c = Gc(); (__c < '0' || __c > '9') && !_eof; __c = Gc()) { if (__c == '-') __f = -1; _eof |= __c == EOF; }
		for (x = 0; __c <= '9' && __c >= '0' && !_eof; __c = Gc()) x = x * 10 + (__c & 15), _eof |= __c == EOF; x *= __f; return !_eof; }
	template <class I> inline void print (I x) { if (!x) pc ('0'); if (x < 0) pc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10; while (qr) pc (qu[qr --]); }
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
} using io::pc; using io::gc; using io::pstr; using io::gstr; using io::gi; using io::print;

template<typename T> inline void chkmax(T&a, T b) { a = a > b ? a : b; }
template<typename T> inline void chkmin(T&a, T b) { a = a < b ? a : b; }
template<typename T> inline T gcd(T&a, T b) { return !b ? a : gcd(b, a % b); }
typedef unsigned uit;
typedef long long ll;
typedef double db;

// 看题目取用
// const int mod1 = 2999999; // for Hash
// const int mod2 = 4999999; // for Hash
// const int mod = 19491001;
// const int mod = 19260817;
// const int mod = 104857601;
// const int mod = 998244353;
// const int mod = 998244853;
// const int mod = 1004535809;
const int mod = 1000000007;

template<typename T>
const T Mod(T x) { return x >= mod * 2 ? x % mod : (x >= mod ? x - mod : x); }
template<typename T>
const void Add(T&a, T b) { a = Mod(a + b); }

const int MAXN = 200100;

int a[MAXN];
ll S[MAXN];

inline ll chk(int n, int x) {
	ll mi = 1LL << 62;
	for(int i = 1; i <= n; i++) {
		int p = upper_bound(a + 1, a + 2 + n, a[i] + x) - a;
		ll nd = (ll)(i - 1) * a[i] - S[i - 1] + S[n] - S[p - 1] - (ll)(n - p + 1) * (a[i] + x);
		chkmin(mi, nd);
	}
	for(int i = n; i >= 1; i--) {
		int p = upper_bound(a, a + 1 + n, a[i] - x) - a;
		ll nd = (ll)(p - 1) * (a[i] - x) - S[p - 1] + S[n] - S[i] - (ll)(n - i) * a[i];
		chkmin(mi, nd);
	}
	return mi;
}

int main() {
#ifndef ONLINE_JUDGE
	FILE("e");
#endif
	int n; gi(n); ll k; gi(k);
	for(int i = 1; i <= n; i++) gi(a[i]);
	sort(a + 1, a + 1 + n); a[n + 1] = 2147483647; a[0] = -a[n];
	for(int i = 1; i <= n; i++) S[i] = S[i - 1] + a[i]; S[n + 1] = S[n];
	int l = 0, r = 1000000000, res = 1000000000;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(chk(n, mid) <= k) res = mid, r = mid - 1;
		else l = mid + 1;
	} printf("%d\n", res);
	return 0;
}