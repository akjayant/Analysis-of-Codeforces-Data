#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long ksm(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=1ll*a*a%mod;
		b/=2;
	}
	return ans;
}
int main()
{
	long long n,m;
	cin>>n>>m;
	long long tot=ksm(2,m);
	tot--;
	long long ans=ksm(tot,n);
	cout<<ans<<'\n';
}