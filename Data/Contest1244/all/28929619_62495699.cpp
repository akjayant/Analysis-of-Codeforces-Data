#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[101010];
long long k;
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(a[l+1]==a[l]) l++;
	while(a[r-1]==a[r]) r--;
	while(k)
	{
		if(l>=r) break;
		if(l>n-r+1)
		{
			if(1LL*(a[r]-a[r-1])*(n-r+1)<=k)
			{
				k-=1LL*(a[r]-a[r-1])*(n-r+1);
				r--;
				while(a[r-1]==a[r]) r--;
			}
			else
			{
				a[r]-=k/(n-r+1);
				k=0;
			}
		}
		else
		{
			if(1LL*(a[l+1]-a[l])*l<=k)
			{
				k-=1LL*(a[l+1]-a[l])*l;
				l++;
				while(a[l+1]==a[l]) l++;
			}
			else
			{
				a[l]+=k/l;
				k=0;
			}
		}
	}
	printf("%d\n",a[r]-a[l]);
	return 0;
}
