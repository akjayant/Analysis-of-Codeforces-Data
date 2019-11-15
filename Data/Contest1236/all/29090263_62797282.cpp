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
  int n; cin >> n;
  vc<vc<int>> ans(n); int nb = 1;
  for(int t=0; t+2*n<=n*n; t+=2*n){
    for(int i=0; i<n; i++) {ans[i].pb(nb); nb++;}
    for(int i=n-1; i>=0; i--) {ans[i].pb(nb); nb++;}
  }
  if(n%2==1){
    for(int i=0; i<n; i++) {ans[i].pb(nb); nb++;}
  }
  for(auto b : ans){
    for(int x : b) cout << x << " ";
    cout << "\n";
  }
  return 0;
}
