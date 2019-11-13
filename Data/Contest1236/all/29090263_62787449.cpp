#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vc vector
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(), x.end()
const int mod = 1000000007;
using pii = pair<int, int>;

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t--){
    int a, b, c; cin >> a >> b >> c;
    int y = min(c/2, b);
    int ans = 3*y;
    b -= y;
    ans += 3*min(a, b/2);
    cout << ans << "\n";
  }
  return 0;
}
