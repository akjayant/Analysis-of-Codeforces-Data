#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fff ff
#define sss ss.ff
#define ttt ss.ss
#define INF (1 << 30)
#define LLF (1ll << 60)
#define PRIME (1000000007)
#define FASTIO std::ios::sync_with_stdio(false)
#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif
#define rep(i, begin, end)                            \
  for (__typeof(end) i = (begin) - ((begin) > (end)); \
       i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#define FILE_INPUT                  \
  freopen("input.txt", "r", stdin); \
  freopen("output.txt", "w", stdout)

#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> ii;
typedef pair<ii, ll> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<string> vs;

/*-----------------END TEMPLATE-----------------*/

bool solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  vi c1(256, 0), c2(256, 0);

  vi diff;
  for (int i = 0; i < n; i++) {
    c1[s[i]]++;
    c2[t[i]]++;
    if (s[i] != t[i]) diff.pb(i);
  }

  if (diff.size() == 0) return true;
  if (diff.size() != 2) return false;

  if (s[diff[0]] == s[diff[1]] && t[diff[0]] == t[diff[1]]) return true;
  return false;
}

int main() {
  FASTIO;
  int k;
  cin >> k;
  while (k--) {
    if (solve()) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
