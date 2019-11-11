#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

template<typename T>
vector<T> gen_v(size_t a) { return vector<T>(a); }
template<typename T, typename ...Ts>
auto gen_v(size_t a, Ts... ts) { return vector<decltype(gen_v<T>(ts...))>(a, gen_v<T>(ts...)); }
template<typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }
template<typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v) { for (auto &e : t) fill_v(e, v); }

template<int MOD>
struct ModInt {
	static const int kMod = MOD;
	unsigned x;
	ModInt() :x(0) {}
	ModInt(signed x_) { x_ %= MOD; if (x_ < 0)x_ += MOD; x = x_; }
	ModInt(signed long long x_) { x_ %= MOD; if (x_ < 0)x_ += MOD; x = x_; }
	int get()const { return (int)x; }
	ModInt &operator+=(ModInt m) { if ((x += m.x) >= MOD)x -= MOD; return *this; }
	ModInt &operator-=(ModInt m) { if ((x += MOD - m.x) >= MOD)x -= MOD; return *this; }
	ModInt &operator*=(ModInt m) { x = (unsigned long long)x*m.x%MOD; return *this; }
	ModInt &operator/=(ModInt m) { return *this *= m.inverse(); }
	ModInt operator+(ModInt m)const { return ModInt(*this) += m; }
	ModInt operator-(ModInt m)const { return ModInt(*this) -= m; }
	ModInt operator*(ModInt m)const { return ModInt(*this) *= m; }
	ModInt operator/(ModInt m)const { return ModInt(*this) /= m; }
	ModInt operator-()const { return ModInt(MOD - (signed)x); }
	bool operator==(ModInt m)const { return x == m.x; }
	bool operator!=(ModInt m)const { return x != m.x; }
	ModInt inverse()const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if (u < 0)u += MOD;
		return ModInt(u);
	}
};
template<int MOD>
ostream &operator<<(ostream &os, const ModInt<MOD> &m) { return os << m.x; }
template<int MOD>
istream &operator>>(istream &is, ModInt<MOD> &m) { signed long long s; is >> s; m = ModInt<MOD>(s); return is; };

template<int MOD>
ModInt<MOD> pow(ModInt<MOD> a, unsigned long long k) {
	ModInt<MOD> r = 1;
	while (k) {
		if (k & 1)r *= a;
		a *= a;
		k >>= 1;
	}
	return r;
}

using mint = ModInt<MOD>;


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s; cin >> s;
	int n = s.size();
	vector<mint> dp(n + 1);
	if (count(all(s), 'm') > 0 || count(all(s), 'w') > 0) {
		cout << 0 << endl;
	}
	else {
		dp[0] = 1;
		rep(i, 0, n) {
			if (i < n && s[i] == 'u' && s[i + 1] == 'u')
				dp[i + 2] += dp[i];
			else if (i < n && s[i] == 'n' && s[i + 1] == 'n')
				dp[i + 2] += dp[i];
			dp[i + 1] += dp[i];
		}
		cout << dp[n] << endl;
	}
	return 0;
}