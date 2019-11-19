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
  int n, m; cin >> n >> m;
  if(n > m) {int tmp = n; n = m; m = tmp;}
  vc<int> fib(m+1); fib[1] = 2; fib[2] = 4;
  for(int i=3; i<=m; i++) {fib[i] = fib[i-1] + fib[i-2]; fib[i]%=mod;}
  int ans = 0;
  if(n==1){
    ans = fib[m];
  } else{
    ans = 6;
    for(int i=1; i<=m-2; i++) {ans += fib[i]; ans %= mod;}
    for(int i=1; i<=n-2; i++) {ans += fib[i]; ans %= mod;}
  }
  cout << ans << "\n";
  return 0;
}
