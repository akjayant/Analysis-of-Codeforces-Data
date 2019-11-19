#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 2e5 + 5;

using ll = long long;

auto split(ll n) {
  vector<ll> ans;
  for (ll x = 2; x * x <= n; ++x) {
    if (n % x == 0) {
      ans.push_back(x);
      while (n % x == 0) {
        n /= x;
      }
    }
  }
  if (n != 1) {
    ans.push_back(n);
  }
  return ans;
}

int main() {
  ll n;
  cin >> n;

  auto ss = split(n);


  if (ss.size() == 1) {
    cout << ss.front() << endl;
  } else {
    cout << 1 << endl;
  }
}
