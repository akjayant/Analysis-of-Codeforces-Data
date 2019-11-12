#include <bits/stdc++.h>
#ifdef local
#include "debug.hpp"
#else
#define debug(...) 0
#endif
using namespace std;
 
#define pb push_back
#define SZ(s) ((int)s.size())
#define ALL(vec) vec.begin(), vec.end()
 
using ll = long long;
template <class T> using V = vector<T>;
template <class T, class U> using P = pair<T, U>;
 
namespace IOTech {
  template <class T> void _R(T& x) { cin >> x; }
  template <class T, class U> void _R(P<T, U>& x) { _R(x.first), _R(x.second); }
  template <class T> void _R(V<T>& v) { for (T& x : v) _R(x); }
  template <class T> void _W(const T& x) { cout << x; }
  template <class T, class U> void _W(const P<T, U>& x) { _W(x.first), _W(' '), _W(x.second); }
  template <class T> void _W(const V<T>& x) { for (int i = 0; i < SZ(x); i++) { _W(x[i]); if (i + 1 < SZ(x)) _W(' '); } }
  void R() {}
  template <class T, class... U> void R(T& val, U&... tail) { _R(val); R(tail...); }
  void W() {}
  template <class T, class... U> void W(const T& val, const U&... tail) { _W(val); _W(sizeof...(tail) ? ' ' : '\n'); W(tail...); }
}
using IOTech::R; using IOTech::W;
 
template <int MOD> class Moduls {
  int val;
  using ll = int64_t;
  using ull = uint64_t;
 
public:
 
  Moduls () { val = 0; }
  Moduls (int x) : val(x % MOD) { if (val < 0) val += MOD; }
  Moduls (ll x) : val(x % MOD) { if (val < 0) val += MOD; }
  Moduls (unsigned x) : val(x % MOD) { if (val < 0) val += MOD; }
  Moduls (ull x) : val(x % MOD) { if (val < 0) val += MOD; }
  Moduls (const Moduls &a) { this->val = a.val; }
 
  explicit operator int() const {
    return val;
  }
  Moduls & operator += (const Moduls b) {
    this->val += b.val;
    if (this->val >= MOD) this->val -= MOD;
    return *this;
  }
  Moduls & operator -= (const Moduls b) {
    this->val -= b.val;
    if (this->val < 0) this->val += MOD;
    return *this;
  }
  Moduls & operator *= (const Moduls b) {
    this->val = (ll)this->val * b.val % MOD;
    return *this;
  }
  Moduls & operator /= (const Moduls b) {
    *this *= b.inv();
    return *this;
  }
  Moduls pow(ll t) const {
    Moduls ret(1), a = *this;
    if (t < 0) a = a.inv(), t = -t;
    for (; t > 0; t /= 2, a *= a) {
      if (t % 2) ret *= a;
    }
    return ret;
  }
  Moduls inv() const {
    int a = MOD, b = this->val;
    int u = 0, v = 1;
    while (b != 0) {
      int t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    return u;
  }
  friend Moduls operator + (const Moduls &a, const Moduls &b) {
    Moduls ret = a;
    ret += b;
    return ret;
  }
  friend Moduls operator - (const Moduls &a, const Moduls &b) {
    Moduls ret = a;
    ret -= b;
    return ret;
  }
  friend Moduls operator * (const Moduls &a, const Moduls &b) {
    Moduls ret = a;
    ret *= b;
    return ret;
  }
  friend Moduls operator / (const Moduls &a, const Moduls &b) {
    Moduls ret = a;
    ret /= b;
    return ret;
  }
  friend bool operator == (const Moduls &a, const Moduls &b) {
    return a.val == b.val;
  }
  friend bool operator != (const Moduls &a, const Moduls &b) {
    return a.val != b.val;
  }
  friend istream & operator >> (istream &in, Moduls &a) {
    int x; in >> x, a = x;
    return in;
  }
  friend ostream & operator << (ostream &out, const Moduls &a) {
    return out << a.val;
  }
};
 
const int mod = 1e9 + 7;
using Mint = Moduls<mod>;
 
template <class T> void uniq(V<T>& v) { sort(ALL(v)), v.erase(unique(ALL(v)), v.end()); }
template <class T> int uniq(T* v, int n) { sort(v, v + n); return unique(v, v + n) - v; }
template <class T, class U> bool chkmin(T& x, U y) { return (y < x) ? (x = y, true) : false; }
template <class T, class U> bool chkmax(T& x, U y) { return (x < y) ? (x = y, true) : false; }
Mint qpow(const Mint& a, ll t) { return a.pow(t); }

void Solution() {
  int n; R(n);
  string s, t; R(s, t);
  V<int> eq(n);
  for (int i = 0; i < n; i++) {
    eq[i] = (s[i] == t[i]);
  }
  int sum = n - accumulate(ALL(eq), 0);
  if (sum != 2 && sum != 0) {
    return W("No");
  }
  if (sum == 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s[i] == s[j]) {
          return W("Yes");
        }
      }
    }
    return W("No");
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!eq[i] && !eq[j]) {
        if (s[i] == s[j] && t[i] == t[j]) {
          return W("Yes");
        } else {
          return W("No");
        }
      }
    }
  }
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout.setf(ios_base::fixed), cout.precision(10);
  int T = 1;
  R(T); // testcase
  while (T--) Solution();
}
