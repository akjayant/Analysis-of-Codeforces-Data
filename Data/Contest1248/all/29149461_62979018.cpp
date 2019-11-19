#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t,n,m,tmp,cnt1,cnt2;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt1 = cnt2 = 0;
		for(int i = 1;i <= n;++i)
		{
			scanf("%d",&tmp);
			if(tmp&1)
				++cnt1;
		}
		scanf("%d",&m);
		for(int i = 1;i <= m;++i)
		{
			scanf("%d",&tmp);
			if(tmp&1)
				++cnt2;
		}
		ll ans = 1ll*cnt1*cnt2+1ll*(n-cnt1)*(m-cnt2);
		printf("%lld\n",ans);
	}
	return 0;
}
