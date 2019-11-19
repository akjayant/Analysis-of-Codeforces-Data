#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef double dl;

#ifdef DEBUG
#include "../debug.h"
#else
#define debug(...) 42
#define cerr if(0) cout
#define endl '\n'
#endif

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()

const int inf = (int) 1.01e9;
const ll infll = (ll) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);
const int mod = (int) 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> div;
  ll n; cin >> n;
  if(n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  for(ll i = 1; i * i <= n; ++i) {
    if(n % i == 0) {
      div.push_back(i);
      div.push_back(n / i);
    }
  }
  sort(ALL(div));
  ll g = div.back();
  div.pop_back();
  for(auto x: div) {
    if(x > 1) g = __gcd(g, x);
  }
  cout << g << '\n';
  return 0;
}
