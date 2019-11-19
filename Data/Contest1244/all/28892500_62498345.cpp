#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n);
  vector<long long> sum(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + a[i];
  }
  auto get_suff = [&](long long x) {
    int l = 0, r = a[n - 1];
    while (l + 1 < r) {
      int m = l + r >> 1;
      int ub = upper_bound(a.begin(), a.end(), m) - a.begin();
      if (sum[n] - sum[ub] - 1ll * (n - ub) * m <= x) {
        r = m;
      } else {
        l = m;
      }
    }
    return r;
  };
  auto get_pref = [&](long long x) {
    int l = a[0], r = a[n - 1];
    while (l + 1 < r) {
      int m = l + r >> 1;
      int ub = upper_bound(a.begin(), a.end(), m) - a.begin();
      if (1ll * ub * m - sum[ub] <= x) {
        l = m;
      } else {
        r = m;
      }
    }
    return l;
  };
  int ans = a[n - 1] - a[0];
  for (int i = 0; i < n; ++i) {
    long long cur = 1ll * a[i] * i - sum[i];
    if (cur > k) {
      break;
    }
    ans = min(ans, max(0, get_suff(k - cur) - a[i]));
  }
  for (int i = n - 1; i >= 0; --i) {
    long long cur = sum[n] - sum[i + 1] - 1ll * a[i] * (n - i - 1);
    if (cur > k) {
      break;
    }
    ans = min(ans, max(0, a[i] - get_pref(k - cur)));
  }
  cout << ans;

  return 0;
}