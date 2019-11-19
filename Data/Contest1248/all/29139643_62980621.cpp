#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+10;

ll a;

int main()
{
	ll t;
	cin>>t;
	while( t-- )
	{
		ll n,m;
		cin>>n;
		ll x1=0,x2=0,y1=0,y2=0;
		for( ll i=1;i<=n;i++ )
		{
			cin>>a;
			if( a%2==1 )
			{
				x1++;
			}
			else x2++;
		}
		cin>>m;
		for( ll i=1;i<=m;i++ )
		{
			cin>>a;
			if( a%2==1 )
			{
				y1++;
			}
			else y2++;
		}
		printf("%lld\n",x1*y1+x2*y2);
	}
}