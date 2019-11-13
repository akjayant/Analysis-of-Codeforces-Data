// By Stefan Radu

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <string>
#include <cctype>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define sz(x) (int)(x).size()

typedef pair < int, int > pii;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;

ll raise(ll a, ll b) {

  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % MOD;
    }

    a = (a * a) % MOD;
    b >>= 1;
  }

  return ans;
}

int main() {

#ifdef STEF
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
#endif

  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;

  cout << raise(raise(2, m) - 1, n) << '\n';
}
