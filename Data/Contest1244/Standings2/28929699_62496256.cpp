#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll k;
ll a[100005];
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ll sum=0;
	if(n%2)
	{
		for(int i=1;i<=n;++i)
		{
			sum+=abs(a[n/2+1]-a[i]);
		}
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			sum+=abs(a[n/2]-a[i]);
		}
	}
	if(k>=sum)
	{
		printf("0\n");
		return 0;
	}
	ll bg=a[1],ed=a[n];
	int pre=1,nxt=n;
	while(pre<=nxt)
	{
		while(pre<nxt&&a[pre]==a[pre+1])++pre;
		while(pre<nxt&&a[nxt-1]==a[nxt])--nxt;
		if(pre==nxt)break;
		if(pre<(n-nxt+1))
		{
			ll val1=(ll)pre*(a[pre+1]-a[pre]);
			if(k<val1)
			{
				bg+=k/(ll)pre;
				break;
			}
			else
			{
				k-=val1;
				bg=a[pre+1];
				++pre;
			}
		}
		else
		{
			ll val2=(ll)(n-nxt+1)*(a[nxt]-a[nxt-1]);
			if(k<val2)
			{
				ed-=k/(ll)(n-nxt+1);
				break;
			}
			else
			{
				k-=val2;
				ed=a[nxt-1];
				--nxt;
			}
		}
	}
	printf("%lld\n",ed-bg);
	return 0;
}