#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lim = 3e2+5;
const int mod = 1e9+7;

int fastexp(ll a,int b) {
	ll ans = 1;
	while(b) {
		if(b&1)
			ans = (ans*a)%mod;
		a = (a*a)%mod;
		b /= 2;
	}
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	swap(n,m);
	ll ans = fastexp(2,n);
	ans = ((ans-1)%mod+mod)%mod;
	ans = fastexp(ans,m);
	cout<<ans;
    return 0;
}