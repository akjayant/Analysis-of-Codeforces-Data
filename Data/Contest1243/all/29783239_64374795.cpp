#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 1005;
int a[maxn];

void solve() {
  int n; cin >> n;
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  sort(a+1, a+n+1, greater<int>());

  for (int i = 1; i <= n; i++) {
    if (a[i] >= i) ans++;
  }

  cout << ans << endl;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int k; cin >> k;

  while (k--) {
    solve();
  }


  return 0;
}
