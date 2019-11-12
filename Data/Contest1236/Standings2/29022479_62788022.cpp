#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#ifdef ConanYu
#include "local.hpp"
#else
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

const int MOD = 1e9 + 7;

int fpow(int a, int b) {
  int ans = 1;
  for(; b; a = 1ll * a * a % MOD, b >>= 1) {
    if(b & 1) {
      ans = 1ll * ans * a % MOD;
    }
  }
  return ans;
}

void Main() {
  int n, m; cin >> n >> m;
  int ans = fpow(2, m);
  ans--;
  if(ans < 0) ans += MOD;
  ans = fpow(ans, n);
  cout << ans << "\n";
}
