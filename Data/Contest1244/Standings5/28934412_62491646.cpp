#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<lu> vu;
typedef vector<v> vv;
typedef vector<vu> vvu;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<set<ll>> vsll;
typedef set<pair<ll, ll>> spll;
typedef vector<spll> vspll;
typedef vector<pll> vpll;
typedef pair<lu, lu> puu;
typedef vector<puu> vpuu;
const ll MOD = 1000000007;
const ld PI = 2 * acos(0.0);
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define round(x, y) ((x + y - 1) / y)
#define ce(x, y) ((x + y - 1) / y)
#define amax(x, y) \
  if (y > x) x = y;
#define amin(x, y) \
  if (y < x) x = y;
#define lcm(x, y) ((x) * (y) / __gcd(x, y))
#define sz(x) (ll) x.size()
#define len(x) (ll) x.length()
#define sq(x) ((x) * (x))
#define cb(x) ((x) * (x) * (x))
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
  if (f) yes else no;
#define noo \
  { no return; }

#define all(x) x.begin(), x.end()

v ga(ll n, bool oneIndexed = false) {
  v a;
  if (oneIndexed) a.push_back(0ll);
  for (ll i = 0; i < n; i++) {
    ll p;
    // scanf("%lld", &p);
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}

vs gas(lu n, bool oneIndexed = false) {
  vs a;
  if (oneIndexed) a.push_back("");
  for (lu i = 0; i < n; i++) {
    string p;
    // scanf("%lu", &p);
    cin >> p;
    a.push_back(p);
  }
  return move(a);
}

template <typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
  if (end == -1) end = sz(a) - 1;
  for (ll i = begin; i <= end; i++) {
    // printf("%lu ", a[i]);
    cout << a[i] << " ";
  }
  cout << endl;
}

template <typename T, typename A>
void papair(vector<T, A> const &a, ll begin = 0, ll end = -1) {
  if (end == -1) end = sz(a) - 1;
  for (ll i = begin; i <= end; i++) {
    // printf("%lu ", a[i]);
    cout << a[i].first << " " << a[i].second << endl;
  }
}
#define MAX (ll)3e5
v visited(MAX, 0);
v c1, c2, c3;
vector<vector<ll>> dp(MAX, v(7));
v mn(MAX, 0);
v isleaf(MAX, 0);
void dfsp(vv &adjList, ll curr, ll prev, ll color) {
  visited[curr] = (color - 1) / 2 + 1;

  v temp;
  ll c = 0;
  for (auto neigh : adjList[curr]) {
    if (neigh == prev) continue;
    if (visited[neigh] == 0) {
      // parents[neigh] = curr;
      if (color == 1) dfsp(adjList, neigh, curr, 3);
      if (color == 2) dfsp(adjList, neigh, curr, 6);
      if (color == 3) dfsp(adjList, neigh, curr, 5);
      if (color == 4) dfsp(adjList, neigh, curr, 2);
      if (color == 5) dfsp(adjList, neigh, curr, 1);
      if (color == 6) dfsp(adjList, neigh, curr, 4);
      temp.push_back(neigh);
    } else if (visited[neigh] == 1) {
    }
  }
  //   visited[curr] = 2;
}
ll dfs(vv &adjList, ll curr, ll prev) {
  visited[curr] = 1;
  v temp;
  ll c = 0;
  for (auto neigh : adjList[curr]) {
    if (neigh == prev) continue;
    if (visited[neigh] == 0) {
      // parents[neigh] = curr;
      int rv = dfs(adjList, neigh, curr);
      temp.push_back(neigh);
      c++;
      //   cout << neigh << " " << c << '\n';
      if (c > 1 || rv == -1) return -1;
    } else if (visited[neigh] == 1) {
      //   ll cycleSize = depths[]
    }
  }
  if (c == 0) {
    isleaf[curr] = 1;
    // mn[curr] = min(c1[curr], c2[curr], c3[curr]);
    dp[curr][1] = c1[curr - 1];
    dp[curr][2] = c1[curr - 1];
    dp[curr][3] = c2[curr - 1];
    dp[curr][4] = c2[curr - 1];
    dp[curr][5] = c3[curr - 1];
    dp[curr][6] = c3[curr - 1];
  } else {
    dp[curr][1] = c1[curr - 1];
    dp[curr][2] = c1[curr - 1];
    dp[curr][3] = c2[curr - 1];
    dp[curr][4] = c2[curr - 1];
    dp[curr][5] = c3[curr - 1];
    dp[curr][6] = c3[curr - 1];
    for (auto neigh : temp) {
      dp[curr][1] += dp[neigh][3];
      dp[curr][2] += dp[neigh][6];
      dp[curr][3] += dp[neigh][5];
      dp[curr][4] += dp[neigh][2];
      dp[curr][5] += dp[neigh][1];
      dp[curr][6] += dp[neigh][4];
    }
  }

  //   visited[curr] = 2;
  return 1;
}
void solve() {
  ll n;
  cin >> n;
  c1.resize(n + 1);
  c2.resize(n + 1);
  c3.resize(n + 1);
  c1 = ga(n);
  c2 = ga(n);
  c3 = ga(n);
  //   ll n, m;
  //   cin >> n >> m;

  vv adjList(n + 1, v(0));
  for (ll i = 0; i < n - 1; i++) {
    ll a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  ll start;
  for (ll i = 0; i < n; i++) {
    if (adjList[i + 1].size() == 1) {
      start = i + 1;
      break;
    }
  }
  // vector<ll> arr = ga(n);
  // code
  int rv = dfs(adjList, start, -1);
  //   for (ll j = 1; j <= 3; j++) {
  //     for (ll i = 0; i < 6; i++) {
  //       cout << dp[j][i + 1] << " ";
  //     }
  //     cout << '\n';
  //   }
  if (rv == -1) {
    cout << rv;
  } else {
    ll mi = 1e18, cc = -1;
    // sort(all(dp[1]));
    for (ll i = 1; i <= 6; i++) {
      if (dp[start][i] < mi) {
        mi = dp[start][i];
        cc = i;
      }
    }
    cout << mi << '\n';
    for (ll i = 1; i <= n; i++) {
      visited[i] = 0;
    }
    dfsp(adjList, start, -1, cc);
    for (ll i = 1; i <= n; i++) {
      cout << visited[i] << " ";
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // ll t;cin >> t;while(t--)
  solve();
  return 0;
}