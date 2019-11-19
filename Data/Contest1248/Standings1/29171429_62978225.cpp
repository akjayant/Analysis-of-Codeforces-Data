#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  int t;
  cin >> t;
  while (t--) {
    ll n, p1 = 0, p2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      ll p;
      cin >> p;
      if (p%2 == 0) p1++;
    }
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      ll q;
      cin >> q;
      if (q%2 == 0) p2++;
    }
    cout << p1*p2 + (n-p1)*(m-p2) << "\n";
  }
}

