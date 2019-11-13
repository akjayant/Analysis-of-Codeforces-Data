#include <iostream>
#include <cmath>

using namespace std;

int t, a, b, c, ans, tmp;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    ans = min(b, c / 2);
    b -= ans;
    ans += min(a, b / 2);
    cout << ans * 3 << endl;
  }
  return 0;
}