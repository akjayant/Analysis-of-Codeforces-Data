#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int f = -1, l = -1;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        f = i;
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      if (s[n-1-i] == '1') {
        l = i;
        break;
      }
    }
    if (f < 0) cout << n << endl;
    else cout << max(2*(n-f), 2*(n-l)) << endl;
  }
}

