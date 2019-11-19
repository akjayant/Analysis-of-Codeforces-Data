#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <set>

using namespace std;

typedef long long i64;
typedef i64 int_t;
typedef vector<int_t> vi;
typedef vector<vi> vvi;

typedef pair<int_t, int_t> pi;
typedef pair<int_t, pi> ppi;

#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define REP(s, e, i) for(i=(s); i < (e); ++i)

int main(int argc, char *argv[]) {

  i64 n, i;
  cin >> n;
  vi x(n), y(n), c(n), k(n);
  REP(0, n, i) {
    cin >> x[i] >> y[i];
  }
  REP(0, n, i) {
    cin >> c[i];
  }
  REP(0, n, i) {
    cin >> k[i];
  }

  vi stations;
  vector<pi> connections;

  vector<ppi> cs(n);
  vi visited(n, 0);
  set<ppi> q;
  REP(0, n, i) {
    cs[i] = ppi(c[i],pi(-1, i));
    q.insert(cs[i]);
  }
  i64 ans = 0;
  while(!q.empty()) {
    ppi t = *q.begin();
    q.erase(q.begin());
    ans += t.first;
    i64 cur = t.second.second;
    visited[cur] = 1;
    if(t.second.first == -1) {
      stations.pb(cur);
    }
    else {
      connections.pb(t.second);
    }

    REP(0, n, i) {
      if(visited[i] == 0) {
	i64 new_cost = (k[i] + k[cur]) *
	  (abs(x[i] - x[cur]) + abs(y[i] - y[cur]));
	if(new_cost < cs[i].first) {
	  ppi new_cs(new_cost, pi(cur, i));
	  q.erase(q.find(cs[i]));
	  q.insert(new_cs);
	  cs[i] = new_cs;
	}
      }
    }
  }

  cout << ans << endl;
  cout << sz(stations) << endl;
  REP(0, sz(stations), i) {
    if(i != 0)
      cout << " ";
    cout << stations[i] + 1;
  }
  cout << endl;
  cout << sz(connections) << endl;
  REP(0, sz(connections), i) {
    cout << connections[i].first + 1 << " " << connections[i].second + 1 << endl;
  }
  return 0;
}
