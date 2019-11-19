#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100000+10;

int n,m,T_T;
int cntp[3],cntq[3];

void init()
{
	memset(cntp,0,sizeof cntp);
	memset(cntq,0,sizeof cntq);
}

int main()
{
	int x;
	scanf("%d",&T_T);
	while(T_T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			++cntp[x&1];
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&x);
			++cntq[x&1];
		}
		ll ans=(ll)cntp[0]*cntq[0]+(ll)cntp[1]*cntq[1];
		printf("%lld\n",ans);
		init();
	}
	
	return 0;
}
