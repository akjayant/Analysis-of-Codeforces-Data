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
void err(T x, Args... args) { cerr << x << ", "; err(args...);}
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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  readfromfile("in.txt");
  int _; cin >> _;
  while(_--) {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    string t; cin >> t;
    vector<char> ans(n, 0);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
      if(t[i] == 'P' && c > 0) {
        ans[i] = 'S'; c--; cnt++;
      } else if(t[i] == 'R' && b > 0) {
        ans[i] = 'P'; b--; cnt++;
      } else if(t[i] == 'S' && a > 0) {
        ans[i] = 'R'; a--; cnt++;
      }
    }
    if(cnt < (n + 1) / 2) cout << "NO\n";
    else {
      cout << "YES\n";
      for(int i = 0; i < n; i++) {
        if(ans[i] == 0) {
          if(a > 0) ans[i] = 'R', a--;
          else if(b > 0) ans[i] = 'P', b--;
          else if(c > 0) ans[i] = 'S', c--;
        }
        cout << ans[i];
      }
      cout << '\n';
    }
  }
  cerr << clock() << " ms\n";
  return 0;
}
