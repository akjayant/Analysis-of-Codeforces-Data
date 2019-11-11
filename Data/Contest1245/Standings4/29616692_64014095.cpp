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

const ll MOD = 1000000007;

int main() {
#ifdef DEBUG
  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<ll> d(s.size() + 10, 0);
    d[0] = 1;
    REP(i, s.size()) {
      if (s[i] == 'm' || s[i] == 'w') {
        d[i + 1] = 0;
      } else if (s[i] == 'n') {
        d[i + 1] = (d[i + 1] + d[i]) % MOD;
        if (i > 0 && s[i - 1] == 'n') {
          d[i + 1] = (d[i + 1] + d[i - 1]) % MOD;
        }
      } else if (s[i] == 'u') {
        d[i + 1] = (d[i + 1] + d[i]) % MOD;
        if (i > 0 && s[i - 1] == 'u') {
          d[i + 1] = (d[i + 1] + d[i - 1]) % MOD;
        }
      } else {
        d[i + 1] = (d[i + 1] + d[i]) % MOD;
      }
    }
    cout << d[s.size()] << '\n';
    return 0;
}
