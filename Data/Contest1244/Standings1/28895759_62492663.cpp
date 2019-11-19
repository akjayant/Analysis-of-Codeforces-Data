#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  //e
  int n;
  cin >> n;
  long long k;
  cin >> k;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    mp[a]++;
  }
  vector<pair<long long, long long>> v;
  for (auto i : mp) {
    v.emplace_back(i.first, i.second);
  }
  n = (int) v.size();
  long long mi = v[0].first, mx = v[n - 1].first;
  int i = 0, j = n - 1;
  while (i < j && k > 0) {
    if (v[i].second <= v[j].second) {
      if (v[i].second * (v[i + 1].first - v[i].first) <= k) {
        mi = v[i + 1].first;
        k -= v[i].second * (v[i + 1].first - v[i].first);
        v[i + 1].second += v[i].second;
        i++;
      } else {
        mi += k / v[i].second;
        break;
      }
    } else {
      if (v[j].second * (v[j].first - v[j - 1].first) <= k) {
        mx = v[j - 1].first;
        k -= v[j].second * (v[j].first - v[j - 1].first);
        v[j - 1].second += v[j].second;
        j--;
      } else {
        mx -= k / v[j].second;
        break;
      }
    }
  }
  cout << mx - mi << '\n';
  return 0;
}