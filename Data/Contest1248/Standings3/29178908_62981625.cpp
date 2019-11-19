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
  int n; cin >> n; vc<int> a(n); for(int i=0; i<n; i++) cin >> a[i];
  sort(all(a)); int b=0, c=0;
  for(int i=0; i<n/2; i++){
    b+=a[i]; c+=a[n-1-i];
  }
  if(n%2==1){c+=a[n/2];}
  int ans = b*b + c*c;
  cout << ans << "\n";
  return 0;
}
	
