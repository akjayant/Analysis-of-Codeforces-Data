#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  int t = min(b, c / 2);
  int ans = 3 * t;
  b -= t;
  t = min(a, b / 2);
  ans += 3 * t;
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i)
    solve();
}