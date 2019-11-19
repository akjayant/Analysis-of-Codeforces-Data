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
    int n;
    string s;
    cin >> n >> s;
    int d = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') d = max(d, max(i + 1, n - i));
    }
    if (d == 0) cout << n << endl;
    else cout << d * 2 << endl;
  }

  return 0;
}
