#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000007];
int main()
{
	ll n,k;
	scanf("%lld %lld",&n,&k);
	ll ans=k;
	k-=(1+n)*n/2;
	if(k<0)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		a[i]=i;
	int left=1;
	int right=n;
	while(k&&left<right)
	{
		if(k>=(right-left))
		{
			k-=(right-left);
			swap(a[left],a[right]);
			left++;
			right--;
		}
		else
		{
			swap(a[left],a[left+k]);
			k=0;
			break;			
		}
	}
	printf("%lld\n",ans-k);
	for(int i=1;i<=n;i++)
		printf("%d%c",a[i]," \n"[i==n]);
	for(int i=1;i<=n;i++)
		printf("%d%c",i," \n"[i==n]);
	return 0;
	
}