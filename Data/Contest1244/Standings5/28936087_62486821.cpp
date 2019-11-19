#include <bits/stdc++.h>
#define MAX 100005
#define ll long long int
using namespace std;

ll n;
ll c[3][MAX];
vector<ll> e[MAX];
bool seen[MAX];
vector<ll> ordered;
vector<vector<ll>> arrange{
  {0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}
};

void dfs(ll at) {
  if (seen[at]) return;
  seen[at] = true;
  ordered.push_back(at);
  for (ll next : e[at]) dfs(next);
}

ll cost_of(ll type, bool print) {
  ll cost = 0;
  for (ll i = 0; i < n; i++) {
    cost += c[arrange[type][i%3]][ordered[i]];
  }
  if (print) {
    vector<ll> out(n, 0);
    for (ll i = 0; i < n; i++) {
      out[ordered[i]] = arrange[type][i%3]+1;
    }
    cout << cost << endl;
    for (ll i = 0; i < n; i++) {
      cout << out[i] << " ";
    }
    cout << endl;
  }
  return cost;
}

int main() {
  cin >> n;
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < n; j++) {
      cin >> c[i][j];
    }
  }

  for (ll i = 1; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    e[x].push_back(y);
    e[y].push_back(x);
  }

  vector<ll> ends;
  for (ll i = 0; i < n; i++) {
    if (e[i].size() == 1) ends.push_back(i);
  }

  // should be a line
  // that has exactly 2 ends
  if (ends.size() != 2) {
    cout << -1 << endl;
    return 0;
  }

  dfs(ends[0]);

  ll best_cost = 3074457345618258602L;
  for (ll i = 0; i < 6; i++) {
    best_cost = min(best_cost, cost_of(i, false));
  }
  for (ll i = 0; i < 6; i++) {
    if (cost_of(i, false) == best_cost) {
      cost_of(i, true);
      return 0;
    }
  }
}
