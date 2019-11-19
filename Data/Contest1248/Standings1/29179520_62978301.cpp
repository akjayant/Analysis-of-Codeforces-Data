#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fll
typedef long long ll;
typedef pair<int,int> pii;
typedef unsigned long long ull;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int cn0=0,cn1=0,cm0=0,cm1=0;
		int n,m;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			if(x&1)cn1++;
			else cn0++;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int x;
			scanf("%d",&x);
			if(x&1)cm1++;
			else cm0++;
		}
		printf("%I64d\n",cn0*1ll*cm0+cn1*1ll*cm1);
	}
	return 0;
}