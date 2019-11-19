#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
signed main()
{
	int n,k;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(a[l]==a[l+1])
		l++;
	while(a[r]==a[r-1])
		r--;
	while(l<r)
	{
		if(l>=n-r+1)
		{
			int tmp=(n-r+1)*(a[r]-a[r-1]);
			if(k<=tmp)
			{
				printf("%lld\n",(a[r]-k/(n-r+1))-a[l]);
				return 0;
			}
			k-=tmp;
			r--;
			while(a[r]==a[r-1])
				r--;
		}
		else
		{
			int tmp=l*(a[l+1]-a[l]);
			if(k<=tmp)
			{
				printf("%lld\n",a[r]-(k/l+a[l]));
				return 0;
			}
			k-=tmp;
			l++;
			while(a[l]==a[l+1])
				l++;
		}
	}
	printf("0\n");
	return 0;
}