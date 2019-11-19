#include <cassert>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <typeinfo>
#include <utility>

using namespace std;

#define ll long long

int main() {
  ll n, p, w, d;

  cin >> n >> p >> w >> d;

  ll rem;

  for (rem = 0; rem < d; rem++) {
    if (p - w * rem >= 0ll && (p - w * rem) % d == 0ll) {
      break;
    }
  }

  if (p - w * rem < 0ll || (p - w * rem) % d != 0ll) {
    cout << "-1\n";
    return 0;
  }

  ll l = 0, r = n / d;

  while (l < r) {
    ll m = (l + r) / 2ll + (l + r) % 2ll;
    ll x = m * d + rem;
    ll y = p - w * x;
    if (y < 0) {
      r = m - 1;
    } else {
      l = m;
    }
  }

  ll x = l * d + rem;
  ll y = (p - w * x) / d;
  if (y < 0 || n - x - y < 0) {
    cout << "-1\n";
    return 0;
  }

  cout << x << " " << y << " " << n - x - y;
  return 0;
}