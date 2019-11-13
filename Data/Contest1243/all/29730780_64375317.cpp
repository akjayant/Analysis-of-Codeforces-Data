#include <bits/stdc++.h>
using namespace std;
int k,n,ans,x;
int a[1005];
int main() {
  cin >> k;
  while(k--) {
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    x = a[n - 1];
    ans = 0;
    for(int i = n - 1; i >= 0; i--) {
      x = min(x, a[i]);
      ans = max(ans, min(n - i, x));
    }
    cout << ans << "\n";
  }
  return 0;
}