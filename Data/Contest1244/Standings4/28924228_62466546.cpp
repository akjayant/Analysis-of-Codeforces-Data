#include <bits/stdc++.h>
#define endl '\n'
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int oo = numeric_limits<int>::max();

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int ansx = (a / c) + (a % c != 0);
    int ansy = (b / d) + (b % d != 0);
    if (ansx + ansy > k) cout << -1 << endl;
    else cout << ansx << " " << ansy << endl;
  }

  return 0;
}
