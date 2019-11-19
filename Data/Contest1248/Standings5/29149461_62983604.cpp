#include<bits/stdc++.h>
#define ll long long
#define INF 1000000
#define MAXN 100005
using namespace std;
int n;
ll minn,sum,a[MAXN];
int main()
{
	while(~scanf("%d",&n))
	{
		minn = 0,sum = 0;
		for(int i = 1;i <= n;++i)
		{
			scanf("%lld",&a[i]);
			sum += a[i];
		}
		sort(a+1,a+n+1);
		for(int i = 1;i <= n/2;++i)
			minn += a[i];
		ll ans = minn*minn+(sum-minn)*(sum-minn);
		printf("%lld\n",ans);
	}
	return 0;
}
