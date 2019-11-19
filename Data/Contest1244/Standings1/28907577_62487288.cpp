#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#ifdef ConanYu
#include "local.hpp"
#else
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

typedef pair<int, int> pii;
void Main() {
  int n; ll k;
  cin >> n >> k;
  map<int, int> mp;
  for(int i = 0; i < n; i++) {
    int t; cin >> t;
    mp[t]++;
  }
  deque<pii> q; // key, value
  for(auto &x: mp) {
    q.emplace_back(x.first, x.second);
  }
  while(k && q.size() > 1) {
    if(q.front().second < q.back().second) {
      pii cur = q.front();
      int key = cur.first, v = cur.second;
      q.pop_front();
      ll need = 1ll * (q.front().first - key) * v;
      if(k >= need) {
        k -= need;
        pii nxt = q.front();
        q.pop_front();
        nxt.second += v;
        q.push_front(nxt);
      } else {
        int p = k / v + key;
        q.push_front({p, 0});
        k = 0;
      }
    } else {
      pii cur = q.back();
      int key = cur.first, v = cur.second;
      q.pop_back();
      ll need = 1ll * (key - q.back().first) * v;
      if(k >= need) {
        k -= need;
        pii nxt = q.back();
        q.pop_back();
        nxt.second += v;
        q.push_back(nxt);
      } else {
        int p = key - k / v;
        q.push_back({p, 0});
        k = 0;
      }
    }
  }
  cout << (q.back().first - q.front().first) << "\n";
}
