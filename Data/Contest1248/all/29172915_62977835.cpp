#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main()
{
	ll n,m,i,j;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ll a=0,b=0,c=0,d=0;
		while(n--)
		{
			ll num;
			scanf("%lld",&num);
			if(num%2==0) a++;
			else b++;
		}
		scanf("%lld",&n);
		while(n--)
		{
			ll num;
			scanf("%lld",&num);
			if(num%2==0) c++;
			else d++;
		}
		printf("%lld\n",a*c+b*d);
	}
	return 0;
}