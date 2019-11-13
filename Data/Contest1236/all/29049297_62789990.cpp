#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define all(x) x.begin(), x.end()
using namespace std; const LD EPS = 1e-9L;
const int N = 100 + 5, LOGN = 20, inf = 1e9, mod = (int)1e9 + 7;
/****************************************************************/
int pow(int x, int n){
	if(n==0) return 1;
	int y = pow(x,n>>1);
	y = ((LL)y*y)%mod;
	if(n&1) y =((LL)y*x)%mod;
	return y;
}
int main() {
      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
      int n,m; cin>>n>>m;
	int ans = ((LL)pow(2,m) - 1 + mod)%mod;
	ans = pow(ans,n);
	cout<<ans<<'\n';
}