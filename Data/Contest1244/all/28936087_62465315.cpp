#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c, d, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d >> k;
    int x = 0;
    int y = 0;
    while (x * c < a) x += 1;
    while (y * d < b) y += 1;
    if (x + y > k) {
      cout << -1 << endl;
    } else {
      cout << x << " " << y << endl;
    }
  }

}
