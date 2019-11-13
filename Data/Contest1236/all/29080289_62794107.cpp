#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
ll powe(ll a,ll b,ll c)
{
	ll ans = 1;
	while(b>0)
	{
		if(b%2==1)
			ans*=a;
		ans=ans%c;
		a=a*a;
		a=a%c;
		b = b/2;
	}
	return ans;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll m,n;
    cin>>n>>m;
    ll base = powe(2,m,mod);
    ll ans = powe((base-1)%mod,n,mod);
    cout<<ans<<endl;
	return 0;
}