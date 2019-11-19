#include <bits/stdc++.h>

using namespace std;
#define int long long
#define inf 1e15
int n;
int a[100001];
int sum[100001];
bool judge(int x,int k)
{
	int at=upper_bound(a+1,a+n+1,x)-a-1;
	int tot=sum[n]-sum[at]-x*(n-at);
	return tot<=k;
}
bool judge2(int x,int k)
{
	int at=upper_bound(a+1,a+n+1,x)-a-1;
	int tot=x*at-sum[at];
	return tot<=k;
}
signed main() 
{
	int k;
	scanf("%I64d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int ans=inf;
	for(int i=1;i<=n;i++)
	{
		int cur=k-(a[i]*i-sum[i]);
		if(cur<0) continue;
		int l=a[i]-1,r=inf;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(judge(mid,cur))
				r=mid;
			else
				l=mid;
		}
		ans=min(ans,r-a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int cur=k-(sum[n]-sum[i]-a[i]*(n-i));
		if(cur<0) continue;
		int l=0,r=a[i]+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			if(judge2(mid,cur))
				l=mid;
			else
				r=mid;
		}
		ans=min(ans,a[i]-l);
	}
	printf("%I64d",max(ans,0ll));
	return 0;
}
/*
4 4
3 100 100 101
*/