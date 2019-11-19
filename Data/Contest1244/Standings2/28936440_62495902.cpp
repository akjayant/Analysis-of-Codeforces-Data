#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int size=1e5+5;
LL a[size];
int main()
{
	int n;
	LL k;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l;
	for(l=1;l<=n;l++)
	{
		if(a[l]!=a[1])break;
	}
	l--;
	int r;
	for(r=n;r>=1;r--)
	{
		if(a[r]!=a[n]) break;
	}
	r++;
	while(l<r)
	{
		if(l<=n-r+1)
		{
			if(k>l*(a[l+1]-a[l]))
			{
				k-=l*(a[l+1]-a[l]);
				l++;
			}
			else break;
		}
		else
		{
			if(k>(n-r+1)*(a[r]-a[r-1]))
			{
				k-=(n-r+1)*(a[r]-a[r-1]);
				r--;
			}
			else break;
		}
	}
	if(l>=r) puts("0");
	else
	{
		LL ans=a[r]-a[l];
		ans-=k/min(l,n-r+1);
		printf("%lld\n",ans);
	}
}