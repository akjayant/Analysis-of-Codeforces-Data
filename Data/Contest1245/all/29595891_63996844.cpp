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
  int t;
  cin >> t;
  for (size_t tt = 0; tt < t; tt++) {
    int a, b;
    cin >> a >> b;
    bool fin = false;
    for (int i = 2; i <= max(a, b); ++i) {
      if ((a % i) == 0 & 0 == (b % i)) {
        fin = true;
        break;
      }
    }
    if (fin) {
      cout << "infinite";
    } else {
      cout << "finite";
    }

    cout << "\n";
  }
  return 0;
}
