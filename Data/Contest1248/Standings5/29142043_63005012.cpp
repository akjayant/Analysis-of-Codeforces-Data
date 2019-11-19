#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],sum[100005];
int main(){
	ll n,m,ans;
	cin >> n >> m;
	ll mod=1e9+7;
	ll tmp=max(n,m);
	a[1]=2; a[2]=4; sum[1]=2; sum[2]=6;
	for(int i=3;i<=tmp;i++) {
		a[i]=(sum[i-2]+4)%mod;
		sum[i]=(sum[i-1]+a[i])%mod;
	}
	ans=a[n];
	if(m==2) ans=(ans+2)%mod;
	if(m==3) ans=(ans+4)%mod;
	if(m>=4) ans=(ans+sum[m-2]+2)%mod;
	cout << ans;
	return 0;
}