#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const ll MOD = 1000000007;
const ll INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(ll i=0;i<(ll)(s.size());++i) {
    cout << s[i];
    if(i == (ll)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
ll dist(ll x1, ll y1, ll x2, ll y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  ll n; cin >> n;
  vector<ll> x(n), y(n);
  for(ll i=0;i<n;++i) {
    cin >> x[i] >> y[i];
  }
  vector<ll> c(n), k(n);
  for(ll i=0;i<n;++i) {
    cin >> c[i];
  }
  for(ll i=0;i<n;++i) {
    cin >> k[i];
  }
  vvi d(n, vi(n, INF));
  for(ll i=0;i<n;++i) {
    for(ll j=0;j<n;++j) {
      d[i][j] = dist(x[i], y[i], x[j], y[j]);
    }
  }
  vector<ll> ansv;
  vector<P> anse;
  ll ans = 0;
  priority_queue<pair<ll, pair<ll, P>>> pq;
  for(ll i=0;i<n;++i) {
    pq.push({-c[i], {i, {-1, -1}}});
  }
  vector<bool> sel(n, false);
  while(!pq.empty()) {
    auto now = pq.top(); pq.pop();
    ll cost = -now.first, idx = now.second.first, u = now.second.second.first, v = now.second.second.second;
    if((idx >= 0 && sel[idx]) || (u >= 0 && sel[v])) continue;
    if(idx >= 0) {
      ansv.push_back(idx);
      ans += cost;
      sel[idx] = true;
    } else if(u >= 0) {
      anse.push_back({u, v});
      ans += cost;
      sel[v] = true;
    }
    for(ll i=0;i<n;++i) {
      if(sel[i]) continue;
      if(idx >= 0) {
        pq.push({-d[idx][i] * (k[idx] + k[i]), {-1, {idx, i}}});
      } else if(u >= 0) {
        pq.push({-d[v][i] * (k[v] + k[i]), {-1, {v, i}}});
      }
    }
  }
  cout << ans << endl;
  cout << (ll)(ansv.size()) << endl;
  for(ll i=0;i<(ll)(ansv.size());++i) {
    cout << ansv[i] + 1;
    if(i == (ll)(ansv.size())-1) cout << endl;
    else cout << " ";
  }
  cout << (ll)(anse.size()) << endl;
  for(ll i=0;i<(ll)(anse.size());++i) {
    cout << anse[i].first + 1 << " " << anse[i].second + 1 << endl;
  }
}
