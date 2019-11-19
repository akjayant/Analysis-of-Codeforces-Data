#include<bits/stdc++.h>
using namespace std;
long long k;
int a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
	long long z1=1,z2=n,val1=1,val2=1;
	while(k>0)
	{
		while(a[z1+1]==a[z1]&&z1<=z2)
		{
			z1++;
			val1++;
		}
		while(a[z2-1]==a[z2]&&z1<=z2)
		{
			z2--;
			val2++;
		}
		if(z1>=z2)
		{
			printf("0");
			return 0;
		}
		if(val1<=val2)
		{
			long long hc=a[z1]-a[z1+1];
			if(hc*val1>k)
			{
				a[z1]-=k/val1;
				break;
			}
			k-=hc*val1;
			a[z1]-=hc;
		}
		if(val1>val2)
		{
			long long hc=a[z2-1]-a[z2];
			if(hc*val2>k)
			{
				a[z2]+=k/val2;
				break;
			}
			k-=hc*val2;
			a[z2]+=hc;
		}
	}
	printf("%d",a[z1]-a[z2]);
	return 0;
}