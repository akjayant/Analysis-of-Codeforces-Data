// Code by H~$~C
//#pragma comment(linker, "/STACK:1024000000,1024000000")
//#pragma GCC optimize("Ofast", "unroll-loops")
//#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define rint register int
#define rep(i, n) for (rint i = 0; i < (n); ++i)
#define rep1(i, n) for (rint i = (1); i <= (n); ++i)
#define Rep(i, a, b) for (rint i = (a); i <= (b); ++i)
#define per(i, n) for (rint i = ((n) - 1); ~i; --i)
#define per1(i, n) for (rint i = (n); i; --i)
#define Per(i, a, b) for (rint i = (a); i >= (b); --i)
#define repit(it, a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define eprintf(...) (fprintf(stderr, __VA_ARGS__) & fflush(stderr))
#define fillset(a, val) memset(a, val, sizeof(a))
#define All(a) a.begin(), a.end()
#define SZ(a) ((int)a.size())
#define fi first
#define se second
#define pb push_back
#define y0 y19260817
#define y1 y19268107
#define j0 j19260817
#define j1 j19268107
#define x0 x19260817
#define x1 x19268107
using namespace std;
#ifndef LOCAL_JUDGE
#define Debug(...)
#else
template <typename T> inline void _debug(const char *names, T &&t) {
(cerr << names << " = " << t << endl).flush();}
template <typename T1, typename ...T>
inline void _debug(const char *names, T1 &&t1, T &&... t) {
const char *comma = strchr(names, ',');
(cerr.write(names, comma - names) << " = " << t1 << ", ").flush();
_debug(comma + 1, t ...);}
#define Debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
#endif
struct __STARTER_OF_PROGRAM__ { __STARTER_OF_PROGRAM__() {
#ifndef ONLINE_JUDGE
  cerr << "Code by H~$~C: \n" << flush;
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(12);
} } __starter_of_program__;
#ifdef LOCAL_JUDGE
struct __ENDDER_OF_PROGRAM__ { ~__ENDDER_OF_PROGRAM__() {
  cerr << "\n\nTime elasped: " << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" << flush;
} } __endder_of_program__;
#endif
using ll = long long; using ull = unsigned long long; using uint = unsigned int;
using ld = long double; using pii = pair<int, int>; using pll = pair<ll, ll>;
using pli = pair<ll, int>; using pil = pair<int, ll>;
template <typename T> using min_queue = priority_queue<T, vector <T>, greater <T> >;
template <typename T> using max_queue = priority_queue<T>;
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
static uniform_int_distribution<int> __disint__;
inline int randint(void) { return __disint__(gen); }
inline int randint(int l, int r) { return __disint__(gen) % (r - l + 1) + l; }
template <typename T> inline void reinit(T &t) { t.~T(); new (&t) T(); }
template <typename T> inline T chmax(T &x, T y) { return x = max(x, y); }
template <typename T> inline T chmin(T &x, T y) { return x = min(x, y); }
template <typename T> inline T chmax(T &x, initializer_list <T> i) { return x = max(x, max(i)); }
template <typename T> inline T chmin(T &x, initializer_list <T> i) { return x = min(x, min(i)); }
inline void read() { } inline void write() { }
template <typename T> inline void read(T &x) { cin >> x; }
template <typename T> inline void write(const T &x) { cout << x; }
template <typename T, typename U>
inline void write(const pair<T, U> &x) { write(x.first), cout.put(' '), write(x.second);}
template <typename T, typename U>
inline void read(pair<T, U> &x) { read(x.first), read(x.second);}
template <typename T, typename ...Ts> inline void read(T &x, Ts &...y) { read(x), read(y...); }
template <typename T, typename ...Ts> inline void write(const T &x, const Ts &...y) {
write(x), (sizeof...(y) && (cout.put(' '), 0)), write(y...); }
#define writeln(...) (write(__VA_ARGS__), cout.put('\n'), 0)
template <typename It> inline void _write(It a, It b) {
register char flag = 0; while (a != b) { flag && (cout.put(' '), 0); write(*a ++), flag = 1; } }
#define _writeln(...) (_write(__VA_ARGS__), cout.put('\n'), 0)
const int mod1 = 1000000007, mod2 = 998244353, mod3 = 1000000009;
const double EPS = 1e-9, PI = acos(-1.0), _E_ = exp(1.0);
const int inf = 0x3f3f3f3f;
const ll lnf = 0x3f3f3f3f3f3f3f3f;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

#define int long long
#define pii pll
ll n, m, k;
vector<pii> v;
vector<ll> row[100005], col[100005];
bool vis[100005][2];
set<int> rs, cs; 
signed main() {
  read(n, m, k);
  if (k == 0) {
    writeln("Yes");
    return 0;
  }
  rep(i, k) {
    int x, y;
    read(x, y);
    --x, --y;
    v.pb({x, y});
    row[x].pb(y);
    col[y].pb(x);
  }
  if (k + n >= 1LL * n * m) {
    vector<vector<bool> > vis(n, vector<bool>(m, 0));
    rep(i, k) vis[v[i].fi][v[i].se] = true;
    ll cnt = 0; 
    rep(i, n) {
      if (!vis[i][0]) ++cnt;
      else break;
    }
    if (cnt == 1LL * n * m - k) {
      writeln("Yes");
      return 0;
    }
  }
  rep(i, n) {
    sort(row[i].begin(), row[i].end());
    sort(col[i].begin(), col[i].end());
  }
  int f = 0;
  int x = 0, y = 0;
  ll tot = 1;
  while (true) {
    if (f % 2 == 0) {
      rs.insert(x);
      vis[x][0] = true;
      int nx, ny;
      if (f == 0) {
        auto it = lower_bound(row[x].begin(), row[x].end(), y); 
        if (it == row[x].end())
          nx = x, ny = m - 1;
        else nx = x, ny = *it - 1;
        auto its = cs.lower_bound(y + 1);
        if (its != cs.end()) ny = min(ny, *its - 1);
      }
      else {
        auto it = upper_bound(row[x].begin(), row[x].end(), y);
        if (it == row[x].begin())
          nx = x, ny = 0;
        else nx = x, ny = *prev(it) + 1;
        auto its = cs.upper_bound(y - 1);
        if (its != cs.begin()) ny = max(ny, *prev(its) + 1);
      }
      if (ny == y) break;
      tot += abs(x - nx) + abs(y - ny);
      x = nx, y = ny;
      if (vis[y][1]) break;
    }
    else {
      cs.insert(y);
      vis[y][1] = true;
      int nx, ny;
      if (f == 1) {
        auto it = lower_bound(col[y].begin(), col[y].end(), x);
        if (it == col[y].end())
          nx = n - 1, ny = y;
        else nx = *it - 1, ny = y;
        auto its = rs.lower_bound(x + 1);
        if (its != rs.end()) nx = min(nx, *its - 1);
      }
      else {
        auto it = upper_bound(col[y].begin(), col[y].end(), x);
        if (it == col[y].begin())
          nx = 0, ny = y;
        else nx = *prev(it) + 1, ny = y;
        auto its = rs.upper_bound(x - 1);
        if (its != rs.begin()) nx = max(nx, *prev(its) + 1);
      }
      if (nx == x) break;
      tot += abs(x - nx) + abs(y - ny);
      x = nx, y = ny;
      if (vis[x][0]) break;
    }
//    Debug(x, y, tot);
    f = (f + 1) % 4;
  }
  if (tot >= 1LL * n * m - k)
    writeln("Yes");
  else writeln("No");
	return 0;
}