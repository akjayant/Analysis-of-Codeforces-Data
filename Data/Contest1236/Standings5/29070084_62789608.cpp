#include <bits/stdc++.h>

using namespace std;

const int maxn = 105;
const int base = 1e9 + 7;

int pw(int x, int n) {
  if (n == 1) return x % base;
  long long res = pw(x, n / 2);
  res = (res * res) % base;
  if (n % 2 == 1) res = (res * x) % base;
  return res;
}

int main() {
  int n, m;
  cin >> n >> m;
  int res = ((pw(2, m) - 1)) % base;
  if (res < 0) res += base;
  res = pw(res, n);
  cout << res;
}