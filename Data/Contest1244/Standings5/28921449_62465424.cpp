#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		ll ans=(a+c-1)/c;
		ll ans2=(b+d-1)/d;
		if(ans+ans2<=k)
		{
			cout<<ans<<" "<<ans2<<endl;
		}
		else
		{
			cout<<"-1\n";
		}
	}
	
}