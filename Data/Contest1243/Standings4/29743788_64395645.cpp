#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define debug(n1) cout << n1 << endl;
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

using namespace std;

const string __sep = "\n";

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n;
  cin >> n;
  for (int x = 2; x * 1ll * x <= n; ++x) {
    if ((n % x) == 0) {
      while ((n % x) == 0) n /= x;
      if (n == 1) {
        cout << x << endl;
      } else cout << 1 << endl;
      return 0;
    }
  }
  cout << n << endl;
   
  return 0;
}
