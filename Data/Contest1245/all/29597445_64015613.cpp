#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vpii vector<pii>
typedef long long ll;
typedef long double ld;
using namespace std;
template<class T> using minheap = priority_queue<T, vector<T>, greater<T>>;

const int N = 2222;
int n;
int x[N], y[N], c[N], k[N];
ll cost[N][N];
int f[N];

int find(int x) {
  return x == f[x] ? x : (f[x] = find(f[x]));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  for (int i = 0; i < N; i++) {
    f[i] = i;
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> k[i];
  }

  vector<vector<ll>> ed;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (i == j) {
        cost[i][i] = c[i];
        ed.pb({c[i], i, n});
      } else {
        cost[i][j] = (k[i] + k[j]) * 1ll * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        ed.pb({cost[i][j], i, j});
      }
    }
  }

  sort(ed.begin(), ed.end());

  vi stat;
  ll tot = 0;
  vpii conn;
  for (auto& vec : ed) {
    int u = vec[1], v = vec[2];
    if (find(u) != find(v)) {
      if (u == n || v == n) {
        stat.pb(u + v - n);
        tot += c[u + v - n];
        f[find(u + v - n)] = find(n);
      } else {
        conn.pb({u, v});
        tot += vec[0];
        f[find(u)] = find(v);
      }
    }
  }

  cout << tot << endl;
  cout << stat.size() << endl;
  for (int x : stat) {
    cout << x + 1 << " ";
  }
  cout << endl;
  cout << conn.size() << endl;
  for (auto pa : conn) {
    cout << pa.f + 1 << " " << pa.s + 1 << " " << endl;
  }

  return 0;
}