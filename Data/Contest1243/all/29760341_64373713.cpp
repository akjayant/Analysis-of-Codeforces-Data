#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> ar(n);
    for(int &x: ar) cin >> x;
    for(int i = n; i >= 1; --i) {
      int cnt = 0;
      for(int x: ar) {
        cnt += (x >= i);
      }
      if(cnt >= i) {
        cout << i << '\n';
        break;
      }
    }
  }
  return 0;
}
