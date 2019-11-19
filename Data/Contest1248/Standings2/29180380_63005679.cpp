#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define all(c) (c).begin(), (c).end()
const int INF = INT_MAX;
const ll LINF = LLONG_MAX;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  P ansPair = P(1, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      string t = s;
      swap(t[i], t[j]);
      t += t;
      vector<int> cnt(2 * n + 1, 0);
      for (int k = 0; k < 2 * n; ++k) {
        if (t[k] == '(') {
          cnt[k + 1] = cnt[k] + 1;
        } else {
          cnt[k + 1] = cnt[k] - 1;
        }
      }
      int mi = *min_element(all(cnt));
      int st = 0;
      while (cnt[st] != mi) {
        ++st;
      }
      if (st > n) break;
      int thisAns = 0;
      for (int i = 0; i < n; ++i) {
        if (cnt[st + i] == mi) ++thisAns;
      }
      if (thisAns > ans && cnt[st] == cnt[st + n]) {
        ans = thisAns;
        ansPair = P(i + 1, j + 1);
      }

      // dump(i, j, t, cnt, thisAns);
    }
  }
  cout << ans << endl;
  cout << ansPair.first << " " << ansPair.second << endl;

  return 0;
}
