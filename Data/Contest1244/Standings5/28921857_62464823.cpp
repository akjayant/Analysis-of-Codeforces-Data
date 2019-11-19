#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int x = -1, y = -1;
    for (int pe = 0; pe <= k; pe++)
      for (int pc = 0; pc <= k-pe; pc++) {
        if (pe*c >= a and pc*d >= b) {
          x= pe;
          y = pc;
          break;
        }
      }
    if (x < 0) cout << -1 << endl;
    else cout << x << " " << y << endl;
  }
}

