#include<map>
#include<cmath>
#include<queue>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

namespace Solve1
{
	const int maxn=100005;
	int n,m,p[maxn],q[maxn],oddp,oddq;
	long long ans;
	void work()
	{
		int T;scanf("%d",&T);
		while(T--)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++) scanf("%d",&p[i]);
			scanf("%d",&m);
			for(int i=1;i<=m;i++) scanf("%d",&q[i]);
			oddp=oddq=0;
			for(int i=1;i<=n;i++) if(p[i]&1) oddp++;
			for(int i=1;i<=m;i++) if(q[i]&1) oddq++;
			ans=(long long)oddp*oddq;
			ans+=(long long)(n-oddp)*(m-oddq);
			cout<<ans<<endl;
		}
		return;
	}
}
int main()
{
	#ifdef LOCAL
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	#endif
	
	Solve1::work();
	
	return 0;
}
