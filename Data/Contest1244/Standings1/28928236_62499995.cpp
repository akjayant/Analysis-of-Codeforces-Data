#include<bits/stdc++.h>
#define mz 1000000007
using namespace std;
int a[100005];
int n;
long long k;
long long suml[100005],sumr[100005];

bool ok1(long long x)
{
	int r=n+1,l=n;
	long long t;
	while(r>1)
	{
		r--;
		while(r>1 && a[r-1]==a[r])
			r--;
		t=max(a[r]-x,0LL);
		while(l>0 && a[l]>t)
			l--;
		if(sumr[r+1]-(n-r)*1LL*a[r]+t*l-suml[l]<=k)
		{
			//cout<<x<<"?1?"<<sumr[r+1]-(n-r)*1LL*a[r]+t*l-suml[l]<<endl;
			return 1;
		}
	}
	return 0;
}
bool ok2(long long x)
{
	int l=0,r=1;
	long long t;
	while(l<n)
	{
		l++;
		while(l<n && a[l+1]==a[l])
			l++;
		t=min(a[l]+x,a[n]*1LL);
		while(r<n+1 && a[r]<=t)
			r++;
		if(a[l]*1LL*l-suml[l]+sumr[r]-t*(n-r+1LL)<=k)
		{
			//cout<<x<<"?2?"<<a[l]*1LL*l-sumr[l]+sumr[r]-t*(n-r+1LL)<<endl;
			return 1;
		}
	}
	return 0;
}

int main()
{
	long long ans,l,r,mid;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		suml[i]=suml[i-1]+a[i];
	for(int i=n;i>=1;i--)
		sumr[i]=sumr[i+1]+a[i];
	ans=a[n/2]*(n/2-1LL)-suml[n/2-1]+sumr[n/2+1]-a[n/2]*(n*1LL-n/2);
	if(k>=ans)
		printf("0\n");
	else
	{
		l=1,r=a[n]-a[1];
		while(l!=r)
		{
			mid=(l+r)/2;
			if(ok1(mid) || ok2(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}