#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifdef local
  #define readfromfile(file) freopen(file, "r", stdin)
  #define debug(...) { cerr << "[" << #__VA_ARGS__ << "] = ["; \
    err(__VA_ARGS__); cerr << "]\n";}
  template<class T>
  void err(T x) { cerr << x;}
  template<class T, class...Args>
  void err(T x, Args... args){ cerr << x << ", ";err(args...);}
#else
  #define debug(...)
  #define readfromfile(...)
  #define endl '\n'
  #define cerr if(0)cout
  #define err(...)
#endif
#define fi first
#define se second
#define empb emplace_back
#define bk back
#define ppb pop_back
#define ins insert
#define clr(a, b) memset(a, b, sizeof a)
#define rep(i, n) for(int i = 0; i < n; i++)
#define ls rt << 1
#define rs rt<<1|1
#define inf 0x3f3f3f3f
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef long double ldb;
typedef complex<double> cpd;
const int N = 3e5 + 7, M = 1 << 10;
const double pi = acos(-1.0);
const int P = 7 * 17 << 23 | 1, G = 3;
const int mod = 1e9 + 7;

int f[N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  readfromfile("in.txt");
  f[1] = 1, f[2] = 2, f[3] = 3;
  for(int i = 4; i < N; i++) {
    f[i] = (2ll * f[i - 2] + f[i - 3]) % mod;
  }
  string s; cin >> s;
  int n = s.size(), res = 1;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'm' || s[i] == 'w') {
      return cout << 0 << endl, 0;
    }
  }
  for(int i = 0, j = 0; i < n; i = j) {
    if(s[i] != 'u' && s[i] != 'n') j++;
    else {
      while(j < n && s[j] == s[i]) j++;
      int sz = j - i;
      res = (ll) res * f[sz] % mod;
    }
  }
  cout << res << endl;
  cerr << clock() << " ms\n";
  return 0;
}
