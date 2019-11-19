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
    int n; cin >> n; int a, b; a=b=0;
    for(int i=0; i<n; i++){int cur; cin >> cur; if(cur%2==0) a++;}
    int m; cin >> m;
    for(int i=0; i<m; i++){int cur; cin >> cur; if(cur%2==0) b++;}
    int ans = a*b + (n-a)*(m-b);
    cout << ans << "\n";
  }
  return 0;
}
