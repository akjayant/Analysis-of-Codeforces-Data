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
  for (size_t tt = 0; tt < t; ++tt) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0;i < n; ++i) {
      cin >> a[i];
    }
    sort(a, a+n, std::greater<int>());
    int res  = n;
    for (int ans = 0; ans < n; ++ans) {
      if (a[ans] < ans + 1) {
        res = ans;
        break;
      }
    }
    cout << res << "\n";
  }

  return 0;
}
