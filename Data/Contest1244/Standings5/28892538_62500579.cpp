#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int l = 0;
  int r = a[n - 1] - a[0];
  while (l < r) {
    int m = (l + r) / 2;
    int smj, smi;
    smi = smj = 0;
    for (int i = 0; i < n; i++) smj += a[i];
    int i, j;
    i = j = 0;
    int ans = k + 1;
    while (i < n) {
      smi+= a[i];
      while (j < n && a[j] - a[i] < m) {
        smj -= a[j];
        j++;
      }
      int cans = (i + 1) * a[i] - smi;
      if (j < n) {
        cans += smj - (n - j) * (a[i] + m);
      } else {
        cans += a[i] + m - a[n - 1];
      }
      ans = min(cans, ans);
      i++;
    }
    i = j = n - 1;
    smi = smj = 0;
    for (int i = 0; i < n; i++) smj += a[i];
    while (i >= 0) {
      smi += a[i];
      while (j >= 0 && a[i] - a[j] < m) {
        smj -= a[j];
        j--;
      }
      int cans = smi - (n - i) * a[i];
      if (j >= 0) {
        cans += (j + 1) * (a[i] - m) - smj;
      } else {
        cans += a[0] - a[i] + m;
      }
      ans = min(cans, ans);
      i--;
    }
    if (ans <= k) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << r;
  return 0;
}