#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+200;
typedef long long ll;



int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int qi1=0,ou1=0,qi2=0,ou2=0;
		int n,m;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int x;scanf("%d",&x);
			if(x%2==0)	qi1++;
			else ou1++;
		}	
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int x;scanf("%d",&x);
			if(x%2==0)	qi2++;
			else ou2++;
		}
		ll ans=1ll*qi1*qi2+1ll*ou2*ou1;
		printf("%lld\n",ans);
	}
} 