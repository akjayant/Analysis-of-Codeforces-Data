#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,p,w,d;
	scanf("%lld %lld %lld %lld",&n,&p,&w,&d);
	ll ma=min(p/w,n);
	for(int i=0;i<=min(ma,d);i++)
	{
		ll temp=ma-i;
		if((p-temp*w)%d==0)
		{
			ll temp2=(p-temp*w)/d;
			if(n<temp+temp2)
				break;
			printf("%lld %lld %lld\n",temp,temp2,n-temp-temp2);
			return 0;
		}
	}
	printf("-1\n");
}