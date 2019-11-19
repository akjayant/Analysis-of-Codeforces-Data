#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define int long long
#define sz(a) (int)(a.size())
#define pb emplace_back

void fast_io() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

signed main() {
  fast_io();
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int min = 0, max = n - 1;
  while (k > 0 && min != max) {
    while (min != max && a[min] == a[min + 1]) {
      ++min;
    }
    while (max != min && a[max] == a[max - 1]) {
      --max;
    }
    if (max == min) {
      break;
    }
    if (min + 1 < n - max) {
      if ((a[min + 1] - a[min]) * (min + 1) <= k) {
        k -= (a[min + 1] - a[min]) * (min + 1);
        a[min] = a[min + 1];
      } else {
        a[min] += k / (min + 1);
        k = 0;
      }
    } else {
      if ((a[max] - a[max - 1]) * (n - max) <= k) {
        k -= (a[max] - a[max - 1]) * (n - max);
        a[max] = a[max - 1];
      } else {
        a[max] -= k / (n - max);
        k = 0;
      }
    }
  }
  cout << a[max] - a[min];
  return 0;
}