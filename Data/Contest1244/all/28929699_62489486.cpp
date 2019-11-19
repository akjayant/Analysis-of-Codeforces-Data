#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll a[1000005],b[1000005];
int main()
{
	scanf("%lld%lld",&n,&k);
	if(k<(n+1)*n/2)
	{
		printf("-1\n");
		return 0;
	}
	ll maxn=0;
	if(n%2)
	{
		maxn=((n-n/2)+n)*(n-(n-n/2)+1)-(n-n/2);
	}
	else
	{
		maxn=((n/2+1)+n)*(n-(n/2+1)+1);
	}
	if(k>maxn)
	{
		printf("%lld\n",maxn);
		for(int i=1;i<=n;++i)
		{
			printf("%d ",i);
		}
		printf("\n");
		for(int i=n;i>=1;--i)
		{
			printf("%d ",i);
		}
		return 0;
	}
	printf("%lld\n",k);
	for(ll i=1;i<=n;++i)
	{
		a[i]=i;
		b[i]=i;
	}
	k-=(n+1)*n/2;
	ll maxcg=n-1,pre=1,nxt=n;
	while(k)
	{
		if(k>=maxcg)
		{
			k-=maxcg;
			swap(a[pre],a[nxt]);
			++pre;
			--nxt;
			maxcg-=2;
		}
		else
		{
			swap(a[pre],a[pre+k]);
			k=0;
		}
	}
	for(int i=1;i<=n;++i)
	{
		printf("%lld ",a[i]);
	}
	printf("\n");
	for(int i=1;i<=n;++i)
	{
		printf("%lld ",b[i]);
	}
	return 0;
}