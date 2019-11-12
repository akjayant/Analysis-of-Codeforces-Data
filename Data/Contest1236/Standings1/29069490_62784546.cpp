#include <algorithm>
#include <iostream>

using namespace std;
int a, b, c;

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    int ans = 0;
    int x = min(b, c / 2);
    ans += x;
    b -= x;
    int y = min(a, b / 2);
    ans += y;
    cout << ans * 3 << endl;
  }
  return 0;
}
