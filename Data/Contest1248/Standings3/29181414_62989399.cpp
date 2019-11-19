#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=100000;
int t,n,m,x;
signed main()
{
	scanf("%lld",&t);
	for(int tot=1;tot<=t;tot++)
	{
		scanf("%lld",&n);
		int evena=0,odda=0,evenb=0,oddb=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x);
			if(x%2==0) evena++;
			else odda++;
		}
		scanf("%lld",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&x);
			if(x%2==0) evenb++;
			else oddb++;
		}
		printf("%lld\n",odda*oddb+evena*evenb);
	}
	return 0;
}
