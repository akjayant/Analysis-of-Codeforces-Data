#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[101010];

int main()
{
	ios::sync_with_stdio(0);
	int n;
	long long k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ls=1,rs=n;
	while(a[ls]<a[rs]&&k>0)
	{
		while(a[ls]==a[ls+1])
			a[ls]=-1,ls++;
		while(a[rs]==a[rs-1])
			a[rs]=-1,rs--;
		int rl=n-rs+1,ll=ls;
		if(ll<rl)
		{
			if(1ll*(a[ls+1]-a[ls])*ll<=k)
				k=k-1ll*(a[ls+1]-a[ls])*ll,ls++;
			else
			{
				k/=ll;
				cout<<a[rs]-a[ls]-k<<endl;
				return 0;
			}
		}
		else
		{
			if(1ll*(a[rs]-a[rs-1])*rl<=k)
				k-=1ll*(a[rs]-a[rs-1])*rl,rs--;
			else
			{
				k/=rl;
				cout<<a[rs]-k-a[ls]<<endl;
				return 0;
			}
		}
	}
	cout<<0<<endl;
	return 0;
}