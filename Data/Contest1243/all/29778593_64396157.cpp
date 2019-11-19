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

vii solve() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;

  vector<priority_queue<int, vi, greater<int>>> c1(256);
  vector<priority_queue<int, vi, greater<int>>> c2(256);

  for (int i = 0; i < n; i++) {
    c1[s[i]].push(i);
    c2[t[i]].push(i);
  }
  vii ans;
  for (int i = 0; i < 256; i++) {
    if ((c1[i].size() + c2[i].size()) % 2 == 1) return ans;
  }

  for (int i = 0; i < n; i++) {
    c1[s[i]].pop();
    c2[t[i]].pop();

    if (s[i] == t[i]) {
      continue;
    }

    char cs = s[i], ct = t[i];

    if (c1[cs].size() > 0) {
      auto sidx = c1[cs].top();
      char temp = s[sidx];
      s[sidx] = t[i];
      t[i] = temp;

      ans.eb(sidx, i);
      c1[ct].push(sidx);
      c1[cs].pop();
    } else if (c2[ct].size() > 0) {
      auto tidx = c2[ct].top();
      char temp = t[tidx];
      t[tidx] = s[i];
      s[i] = temp;

      ans.eb(i, c2[ct].top());
      c2[cs].push(c2[ct].top());
      c2[ct].pop();
    } else {
      auto first = c1[ct].top();

      char temp = s[first];
      s[first] = t[i + 1];
      t[i + 1] = temp;

      ans.eb(first, i + 1);
      c1[ct].pop();
      c2[t[i + 1]].pop();
      c1[t[i + 1]].push(first);

      temp = s[i];
      s[i] = t[i + 1];
      t[i + 1] = temp;

      ans.eb(i, i + 1);
      c2[cs].push(i + 1);
    }
  }
  return ans;
}

int main() {
  FASTIO;
  ll n;
  cin >> n;
  ll gcd = n;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i != 0) continue;
    gcd = __gcd(gcd, i);
    gcd = __gcd(gcd, n / i);
  }
  cout << gcd << endl;
}
