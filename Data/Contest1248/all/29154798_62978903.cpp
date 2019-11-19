#include <bits/stdc++.h>

using namespace std;
#define int long long
int T;
int n,m;
int a[100005],b[100005];

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		int s1=0,s2=0,s3=0,s4=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
			if(a[i]%2==0)
			{
				s1++;
			}
			else
			{
				s2++;
			}
		}
		scanf("%lld",&m);
		for(int i=1;i<=m;++i)
		{
			scanf("%lld",&b[i]);
			if(b[i]%2==0)
			{
				s3++;
			}
			else
			{
				s4++;
			}
		}
		printf("%lld\n",s1*s3+s2*s4);
	} 
	return 0;
}