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

int cal(int a, int b){
  if(b==1) return a%mod;
  else if(b==0) return 1;
  else if(b%2==1) return (a*cal(a, b-1))%mod;
  else return (cal(a, b/2) * cal(a, b/2))%mod;
}

signed main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  int a = (cal(2, m) -1 + mod)%mod;
  int ans = cal(a, n);
  cout << ans << "\n";
  return 0;
}
	
