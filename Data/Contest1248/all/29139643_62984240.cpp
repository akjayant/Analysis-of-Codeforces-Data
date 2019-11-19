#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e5+10;

ll a[maxn];

int main()
{
	int n;
	cin>>n;
	for( int i=1;i<=n;i++ ) cin>>a[i];
	sort(a+1,a+1+n);
	ll ans1=0,ans2=0;
	for( int i=n;i>n/2;i-- )
	{
		ans1+=a[i];
	}
	for( int i=n/2;i>=1;i-- )
	{
		ans2+=a[i];
	}
	printf("%lld\n",ans1*ans1+ans2*ans2);
	
}