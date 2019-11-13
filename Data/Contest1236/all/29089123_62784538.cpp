#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll=long long;

main()
{
	ll t,a,b,c;
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b>>c;
		
		ll ans=0,tmp;
		
		tmp=min(c/2,b);
		ans+=3*tmp;
		b-=tmp;
		
		ans+=3*min(a,b/2);
		
		cout<<ans<<endl;
	}
}