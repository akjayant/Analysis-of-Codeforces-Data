#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int main(int argc, char **argv) {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    int res = n;
    for(int i=0; i<n; i++) {
      if(s[i] == '1') {
        res = max(res, 2*max(i+1, n-i));
      }
    }
    cout << res << endl;
  }

  return 0;
}