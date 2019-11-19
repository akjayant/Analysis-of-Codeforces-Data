#include<bits/stdc++.h>
#define ll long long
#define MAX_N 100010
using namespace std;
const ll mod=1e9+7;
ll f[MAX_N];
int main()
{
	ios::sync_with_stdio(false);
	ll n,m;
	cin>>n>>m;
	f[0]=f[1]=1;
	for(ll i=2,x;i<=max(n,m);++i)
		f[i]=(f[i-1]+f[i-2])%mod;
	cout<<2ll*(f[n]+f[m]-1)%mod<<endl;
	return 0;
}