#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define int long long

signed main() {
  int n, p, w, d;
  cin >> n >> p >> w >> d;
  int start = p % w;
  int wins = 0, draws = 0, losses = 0;
  bool first = true;
  while (((p - draws * d) % w != 0) && ((p - draws * d) % w != start || first) &&
      (p - draws * d > 0)) {
    draws++;
    first = false;
  }
  if ((p - draws * d) % w == 0) {
    wins = (p - draws * d) / w;
    losses = n - wins - draws;
  } else if (p % d == 0) {
    draws = p / d;
    losses = n - draws;
  } else {
    cout << -1;
    return 0;
  }
  if (losses < 0 || wins < 0 || draws < 0) {
    cout << -1;
  } else {
    cout << wins << ' ' << draws << ' ' << losses;
  }
}