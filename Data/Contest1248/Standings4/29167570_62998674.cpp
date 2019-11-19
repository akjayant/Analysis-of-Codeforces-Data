#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;

const int N = 1e5 + 2;
const int mod = 1e9 + 7;

int main() {
  vector<ll> prv = {0, 2, 2};
  for (int i = 3; i <= N; ++i) {
    prv.push_back((prv[i - 1] + prv[i - 2]) % mod);
  }
  int n, m; cin >> n >> m;
  ll st = 2;
  for (int i = 1; i <= n - 1; ++i) {
    st = (st + prv[i]) % mod;
  }
  for (int i = 1; i <= m - 1; ++i) {
    st = (st + prv[i]) % mod;
  }
  cout << st << endl;
  // for (x = 1; x <= 15; ++x) {
  //   for (y = 1; y <= 15; ++y) {
  //     memset(g, -1, sizeof g);
  //     memset(cnt, 0, sizeof cnt);
  //     ans = 0; 
  //     bt(0, 0);
  //     printf("[%d][%d] = %d\n", x, y, ans);
  //   }
  // }
  return 0;
}