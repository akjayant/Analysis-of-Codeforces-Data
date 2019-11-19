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

int ansx[MAXN];

int a[10];
int t[10];
int d[MAXN];
int id[MAXN];
int c[10][MAXN];

int tot;
int to[MAXN << 1];
int ne[MAXN << 1];
int fi[MAXN];

int s[MAXN];
int p[MAXN];
int tp;

inline void Link(int u, int v) {
	tot++;
	to[tot] = v;
	ne[tot] = fi[u];
	fi[u] = tot;
}


void dfs(int x, int la) {
	p[++tp] = x, s[x] = tp;
	for(int i = fi[x]; i; i = ne[i]) {
		int u = to[i];
		if(u == la)  continue;
		dfs(u, x);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	FILE("d");
#endif
	int n; gi(n);
	for(int i = 1; i <= n; i++) gi(c[0][i]);
	for(int i = 1; i <= n; i++) gi(c[1][i]);
	for(int i = 1; i <= n; i++) gi(c[2][i]);
	for(int i = 1; i < n; i++) {
		int u, v; gi(u), gi(v);
		Link(u, v), Link(v, u);
		d[u]++, d[v]++;
		if(d[u] > 2 || d[v] > 2) {
			pstr("-1");
			return 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		if(d[i] == 1) {
			dfs(i, i);
			break;
		}
	}
	ll res = 1LL << 62, ans;
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3;j++) {
			if(i == j)  continue;
			a[1]=i, a[2]=j, a[0]=0;
			while(a[0] == i || a[0] == j) ++a[0];
			ans = 0;
			for(int k = 1; k <= n; k++)
				ans += c[a[k % 3]][p[k]];
			if(ans < res) {
				res = ans;
				for(int k = 1; k <= n; k++)
					id[k] = a[k % 3] + 1;
			}
		}
	} print(res), pc('\n');
	for(int i=1;i<=n;i++)  print(id[s[i]]), pc(' ');
	pc('\n');
	return 0;
}