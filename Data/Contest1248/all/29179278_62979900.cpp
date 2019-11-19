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
    int n, m;
    cin >> n;
    ll p[] = {0, 0};
    ll q[] = {0, 0};
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      p[x % 2]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      q[x % 2]++;
    }
    cout << p[0] * q[0] + p[1] * q[1] << endl;
  }

  return 0;
}
