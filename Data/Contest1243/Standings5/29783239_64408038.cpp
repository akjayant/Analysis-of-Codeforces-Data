#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
set<ll> factors;

void find_factors() {
  for (ll i = 2; i*i <= n; i++) {
    if (n%i == 0) {
      factors.insert(i);
      factors.insert(n/i);
    }
  }
}

ll gcd(ll a, ll b) {
  if (a == 0) return b;
  return gcd(b%a, a);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  cin >> n;
  find_factors();

  if (factors.size() == 0) { // n is PRIME / 1
    cout << n << endl;
  } else {
    ll g = n;
    for (auto x: factors) {
      g = gcd(g, x);
    }
    cout << g << endl;
  }

  return 0;
}
