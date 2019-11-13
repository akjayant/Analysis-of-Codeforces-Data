#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>

#ifdef DEBUG
#define dbg(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define dbg(fmt, args...)
#endif
#define REPS(i, s, n) for(int (i) = (s); (i) < (int)(n); ++(i))
#define REPRS(i, e, n) for(int (i) = (int)(n) - 1; (i) >= e; --(i))
#define REPR(i, n) REPRS(i, 0, n)
#define REP(i, n) REPS(i, 0, n)
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define x first
#define y second
#define INFI 1234567890
#define INFL 1234567890123456789LL
typedef double dbl;
typedef long double ldbl;
typedef long long ll;

using namespace std;
// R P S
int WINS[3] = {2,0,1};
int LOSES[3] = {1,2,0};

void solve() {
  int n;
  cin >> n;
  string vs = "RPS";
  map<char, int> m;
  m['R'] = 0;
  m['P'] = 1;
  m['S'] = 2;
  int v[2][3] = {0};
  REP(i, 3) cin >> v[0][i];
  string s;
  cin >> s;
  REP(i, n) {
    v[1][m[s[i]]]++;
  }
  int wins = 0;
  int rest[3] = {0};
  REP(i, 3) {
    wins += min(v[0][i], v[1][WINS[i]]);
    rest[i] = v[0][i] - min(v[0][i], v[1][WINS[i]]);
  }
  dbg("wins = %d\n", wins);

  if (wins < (n + 1) / 2) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    string ans;
    REP(i, n) {
      int res = LOSES[m[s[i]]];
      dbg("%d\n", res);
      if (v[0][res] > 0) {
        ans += vs[res];
        v[0][res]--;
      } else {
        REP(j, 3) {
          if (rest[j] > 0) {
            ans += vs[j];
            rest[j]--;
            break;
          }
        }
      }
      
    }
    cout << ans << "\n";
  }
}

int main() {
#ifdef DEBUG
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    REP(t_id, t) {
      solve();
    }
    return 0;
}
