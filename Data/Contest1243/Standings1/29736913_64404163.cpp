#include<bits/stdc++.h>

const int maxn=102020;
long long n;
long long gcd(long long a,long long  b){return b==0?a:gcd(b,a%b);}
int main()
{
#ifdef LOCAL
	freopen("input.txt","r",stdin);
#endif
	scanf("%lld",&n);
	long long ans=0;
	for(long long i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			ans=gcd(ans,i);
			ans=gcd(ans,n/i);
		}
	}
	printf("%lld\n",gcd(ans,n));
	return 0;
}