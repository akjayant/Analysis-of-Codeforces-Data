#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll=long long;

ll power(ll a,ll n)
{
	ll ref=1;
	
	while(n)
	{
		if(n%2)
		ref=(ref*a)%MOD;
		
		a=(a*a)%MOD;
		
		n/=2;
	}
	
	return ref;
}

main()
{
	ll n,m;
	
	cin>>n>>m;
	
	cout<<power((power(2,m)-1+MOD)%MOD,n);
}