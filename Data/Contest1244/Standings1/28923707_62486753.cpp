#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<ll, ll>;

int main(int argc, char **argv) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  ll k; cin >> k;
  map<ll, ll> c;
  for(int i=0; i<n; i++) {
    int x; cin >> x;
    c[x]++;
  }

  deque<pii> d;
  for(pii it : c) d.push_back(it);

  while(d.size() > 1) {
    if(d.front().second < d.back().second) {
      pii t = d.front();
      d.pop_front();
      ll dist = 1LL*abs(t.first - d.front().first);
      ll mv = min(k/t.second, dist);
      if(mv != dist) {
        d.push_front({t.first+mv, t.second});
      } else {
        d.front().second += t.second;
      }
      k -= mv * t.second;
      if(!mv) break;
    }
    else {
      pii t = d.back();
      d.pop_back();
      ll dist = 1LL*abs(t.first - d.back().first);
      ll mv = min(k/t.second, dist);
      if(mv != dist) {
        d.push_back({t.first-mv, t.second});
      } else {
        d.back().second += t.second;
      }
      k -= mv * t.second;
      if(!mv) break;
    }

  }

  // for(pii it : d) cout << it.first << ' ' << it.second << endl;
  cout << d.back().first - d.front().first << endl;

  return 0;
}