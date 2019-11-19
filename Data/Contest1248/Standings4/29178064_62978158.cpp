#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n; cin>>n;
		ll a[n];
		ll e1=0,o1=0;
		for(ll i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]%2==0)
			  e1++;
			else
			  o1++;
		}
		ll m; cin>>m;
		ll b[m];
		ll e2=0,o2=0;
		for(ll i=0;i<m;i++)
		{
			cin>>b[i];
			if(b[i]%2==0)
			  e2++;
			else
			  o2++;
		}
		ll ans;
		ans=e1*e2;
		ans+=o1*o2;
		cout<<ans<<endl;
	}
	return 0;
}