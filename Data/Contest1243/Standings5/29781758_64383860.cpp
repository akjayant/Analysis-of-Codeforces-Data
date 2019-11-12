#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  int j0 = -1;
  int j1 = -1;
  for (int i = 0; i < n; i++) {
    if (s.at(i) == t.at(i)) continue;
    if (j0 < 0) {
      j0 = i;
    }else if (j1 < 0) {
      j1 = i;
    }else {
      cout << "No\n";
      return;
    }
  }
  assert (j0 >= 0);
  if (j1 < 0) {
    cout << "No\n";
    return;
  }
  if (s.at(j0) == s.at(j1) && t.at(j0) == t.at(j1)) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }
}


int main(int argc, char *argv[]) {
  // C-style stdio functions should not be used.
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  int k; cin >> k;
  for (int kk = 0; kk < k; kk++) {
    solve();
  }

  return 0;
}

